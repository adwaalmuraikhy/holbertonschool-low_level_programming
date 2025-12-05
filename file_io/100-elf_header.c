#include "main.h"
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * check_elf - checks if a file is an ELF file
 * @e_ident: pointer to the ELF identification bytes
 */
void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 && e_ident[i] != 'E' &&
		    e_ident[i] != 'L' && e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - prints ELF magic bytes
 * @e_ident: pointer to the ELF identification bytes
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i != EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * print_class - prints ELF class
 * @e_ident: pointer to the ELF identification bytes
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - prints ELF data encoding
 * @e_ident: pointer to the ELF identification bytes
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**void print_osabi(unsigned char *e_ident)
{
        printf("  OS/ABI:                            ");
        switch (e_ident[EI_OSABI])
        {
        case ELFOSABI_SYSV:
                printf("UNIX - System V\n");
                break;
        case ELFOSABI_LINUX:
                printf("UNIX - Linux\n");
                break;
        case ELFOSABI_FREEBSD:
                printf("UNIX - FreeBSD\n");
                break;
        case ELFOSABI_SOLARIS:
                printf("UNIX - Solaris\n");
                break;
        default:
                printf("<unknown: %x>\n", e_ident[EI_OSABI]);
        }
}

 * print_version - prints ELF version
 * @e_ident: pointer to the ELF identification bytes
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)");
	printf("\n");
}

/**
 * print_osabi - prints ELF OS/ABI
 * @e_ident: pointer to the ELF identification bytes
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi_version - prints ELF ABI version
 * @e_ident: pointer to the ELF identification bytes
 */
void print_abi_version(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints ELF file type
 * @e_type: ELF type
 * @e_ident: pointer to the ELF identification bytes
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");
	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - prints ELF entry point address
 * @e_entry: entry point address
 * @e_ident: pointer to the ELF identification bytes
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0x00FF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("0x%x\n", (unsigned int)e_entry);
	else
		printf("0x%lx\n", e_entry);
}

/**
 * close_elf - closes an ELF file descriptor
 * @fd: file descriptor
 */
void close_elf(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}
}

/**
 * read_elf_header - reads ELF header from a file
 * @fd: file descriptor
 * @header: pointer to ELF header structure
 */
void read_elf_header(int fd, Elf64_Ehdr *header)
{
	ssize_t n;

	n = read(fd, header, sizeof(Elf64_Ehdr));
	if (n != (ssize_t)sizeof(Elf64_Ehdr))
	{
		dprintf(STDERR_FILENO, "Error: Can't read ELF header\n");
		close_elf(fd);
		exit(98);
	}
}

/**
 * main - displays the information contained in the ELF header
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, exits with 98 on error
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	read_elf_header(fd, &header);
	check_elf(header.e_ident);

	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);
	print_abi_version(header.e_ident);
	print_type(header.e_type, header.e_ident);
	print_entry(header.e_entry, header.e_ident);

	close_elf(fd);
	return (0);
}

