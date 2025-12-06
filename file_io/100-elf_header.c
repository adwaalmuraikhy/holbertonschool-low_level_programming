#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * check_elf - checks if a file is an ELF file
 * @e_ident: pointer to the ELF identification bytes
 */
void check_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != 0x7f ||
	    e_ident[EI_MAG1] != 'E' ||
	    e_ident[EI_MAG2] != 'L' ||
	    e_ident[EI_MAG3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * print_magic - prints ELF magic bytes
 * @e_ident: pointer to ELF identification bytes
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * print_class - prints ELF class
 * @e_ident: pointer to ELF identification bytes
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
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
 * @e_ident: pointer to ELF identification bytes
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
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

/**
 * print_version - prints ELF version
 * @e_ident: pointer to ELF identification bytes
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
 * @e_ident: pointer to ELF identification bytes
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi_version - prints ABI version
 * @e_ident: pointer to ELF identification bytes
 */
void print_abi_version(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints ELF file type
 * @e_type: ELF type value
 * @e_ident: pointer to ELF identification bytes
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");
	switch (e_type)
	{
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - prints ELF entry point address
 * @e_entry: entry point value
 * @e_ident: ELF identification
 */
void print_entry(unsigned long e_entry, unsigned char *e_ident)
{
	unsigned long value = e_entry;
	unsigned char *p = (unsigned char *)&e_entry;
	int i, bytes;

	if (e_ident[EI_CLASS] == ELFCLASS32)
		bytes = 4;
	else
		bytes = 8;

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		value = 0;
		for (i = 0; i < bytes; i++)
		{
			value <<= 8;
			value |= p[i];
		}
		e_entry = value;
	}

	printf("  Entry point address:               ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - closes ELF file
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
 * main - displays ELF header info
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr header;
	int fd;
	ssize_t r;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	r = read(fd, &header, sizeof(header));
	if (r != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		close_elf(fd);
		exit(98);
	}

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
