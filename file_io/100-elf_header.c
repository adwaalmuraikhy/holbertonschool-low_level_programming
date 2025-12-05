#include "main.h"
#include <elf.h>
#include <stdio.h>

/**
 * print_magic - prints ELF magic bytes
 * @e_ident: ELF identification array
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
 * @e_ident: ELF identification array
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
 * @e_ident: ELF identification array
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
		printf("none\n");
	}
}

/**
 * print_version - prints ELF version
 * @e_ident: ELF identification array
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)");
	printf("\n");
}

/**
 * print_osabi - prints ELF OS/ABI
 * @e_ident: ELF identification array
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
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi_version - prints ELF ABI version
 * @e_ident: ELF identification array
 */
void print_abi_version(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * get16 - read 16-bit value with ELF endianness
 * @p: pointer to bytes
 * @data: EI_DATA value
 *
 * Return: 16-bit value
 */
unsigned short get16(unsigned char *p, int data)
{
	if (data == ELFDATA2MSB)
		return ((unsigned short)p[0] << 8) | p[1];
	return ((unsigned short)p[1] << 8) | p[0];
}

/**
 * get32 - read 32-bit value with ELF endianness
 * @p: pointer to bytes
 * @data: EI_DATA value
 *
 * Return: 32-bit value
 */
unsigned long get32(unsigned char *p, int data)
{
	if (data == ELFDATA2MSB)
		return ((unsigned long)p[0] << 24) |
		       ((unsigned long)p[1] << 16) |
		       ((unsigned long)p[2] << 8) |
		       (unsigned long)p[3];
	return ((unsigned long)p[3] << 24) |
	       ((unsigned long)p[2] << 16) |
	       ((unsigned long)p[1] << 8) |
	       (unsigned long)p[0];
}

/**
 * get64 - read 64-bit value with ELF endianness
 * @p: pointer to bytes
 * @data: EI_DATA value
 *
 * Return: 64-bit value
 */
unsigned long long get64(unsigned char *p, int data)
{
	unsigned long long val = 0;
	int i;

	if (data == ELFDATA2MSB)
	{
		for (i = 0; i < 8; i++)
			val = (val << 8) | p[i];
	}
	else
	{
		for (i = 7; i >= 0; i--)
			val = (val << 8) | p[i];
	}
	return (val);
}

/**
 * print_type - prints ELF file type
 * @e_ident: ELF identification
 * @buf: full ELF header buffer
 */
void print_type(unsigned char *e_ident, unsigned char *buf)
{
	unsigned short type;
	int data = e_ident[EI_DATA];

	type = get16(buf + 16, data);
	printf("  Type:                              ");
	switch (type)
	{
	case ET_NONE:
		printf("NONE (No file type)\n");
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
		printf("<unknown: %x>\n", type);
	}
}

/**
 * print_entry - prints entry point address
 * @e_ident: ELF identification
 * @buf: full ELF header buffer
 */
void print_entry(unsigned char *e_ident, unsigned char *buf)
{
	unsigned long long entry;
	int data = e_ident[EI_DATA];

	if (e_ident[EI_CLASS] == ELFCLASS32)
		entry = get32(buf + 24, data);
	else
		entry = get64(buf + 24, data);

	printf("  Entry point address:               0x%lx\n",
	       (unsigned long)entry);
}

/**
 * main - displays information from ELF header
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	int fd;
	ssize_t r;
	unsigned char hdr[64];

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

	r = read(fd, hdr, sizeof(hdr));
	if (r < 0 || r < 24)
	{
		dprintf(STDERR_FILENO, "Error: Can't read ELF header from %s\n",
			argv[1]);
		close(fd);
		exit(98);
	}

	if (hdr[0] != 0x7f || hdr[1] != 'E' ||
	    hdr[2] != 'L' || hdr[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", argv[1]);
		close(fd);
		exit(98);
	}

	print_magic(hdr);
	print_class(hdr);
	print_data(hdr);
	print_version(hdr);
	print_osabi(hdr);
	print_abi_version(hdr);
	print_type(hdr, hdr);
	print_entry(hdr, hdr);

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}

	return (0);
}
