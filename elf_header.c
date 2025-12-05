#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * elf_get16 - extracts a 16-bit value respecting endianness
 * @p: pointer to bytes
 * @data: ELFDATA2LSB or ELFDATA2MSB
 * Return: 16-bit value
 */
unsigned short elf_get16(const unsigned char *p, int data)
{
    if (data == ELFDATA2MSB)
        return ((unsigned short)p[0] << 8) | p[1];
    return ((unsigned short)p[1] << 8) | p[0];
}

/**
 * elf_get32 - extracts a 32-bit value respecting endianness
 * @p: pointer to bytes
 * @data: ELFDATA2LSB or ELFDATA2MSB
 * Return: 32-bit value stored as unsigned long
 */
unsigned long elf_get32(const unsigned char *p, int data)
{
    unsigned long val;

    if (data == ELFDATA2MSB)
    {
        val = ((unsigned long)p[0] << 24) |
              ((unsigned long)p[1] << 16) |
              ((unsigned long)p[2] << 8) |
              (unsigned long)p[3];
    }
    else
    {
        val = ((unsigned long)p[3] << 24) |
              ((unsigned long)p[2] << 16) |
              ((unsigned long)p[1] << 8) |
              (unsigned long)p[0];
    }
    return (val);
}

/**
 * elf_get64 - extracts a 64-bit value respecting endianness
 * @p: pointer to bytes
 * @data: ELFDATA2LSB or ELFDATA2MSB
 * Return: 64-bit value stored inside unsigned long
 */
unsigned long elf_get64(const unsigned char *p, int data)
{
    unsigned long val = 0;
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
 * main - displays the ELF header information
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
    int fd;
    ssize_t r;
    unsigned char h[64];
    int i;
    int data, class;
    unsigned short type;
    unsigned long entry;
    int len;

    if (argc != 2)
    {
        write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        write(STDERR_FILENO, "Error: Can't read file ", 23);
        len = 0;
        while (argv[1][len])
            len++;
        write(STDERR_FILENO, argv[1], len);
        write(STDERR_FILENO, "\n", 1);
        exit(98);
    }

    r = read(fd, h, sizeof(h));
    if (r < 24)
    {
        write(STDERR_FILENO, "Error: Can't read ELF header from ", 34);
        len = 0;
        while (argv[1][len])
            len++;
        write(STDERR_FILENO, argv[1], len);
        write(STDERR_FILENO, "\n", 1);
        close(fd);
        exit(98);
    }

    if (h[0] != 0x7f || h[1] != 'E' || h[2] != 'L' || h[3] != 'F')
    {
        write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
        close(fd);
        exit(98);
    }

    printf("ELF Header:\n");

    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", h[i]);
        if (i != EI_NIDENT - 1)
            printf(" ");
    }
    printf("\n");

    printf("  Class:                             ");
    class = h[EI_CLASS];
    if (class == ELFCLASS32)
        printf("ELF32\n");
    else if (class == ELFCLASS64)
        printf("ELF64\n");
    else
        printf("none\n");

    printf("  Data:                              ");
    data = h[EI_DATA];
    if (data == ELFDATA2LSB)
        printf("2's complement, little endian\n");
    else if (data == ELFDATA2MSB)
        printf("2's complement, big endian\n");
    else
        printf("none\n");

    printf("  Version:                           %d", h[EI_VERSION]);
    if (h[EI_VERSION] == 1)
        printf(" (current)");
    printf("\n");

    printf("  OS/ABI:                            ");
    switch (h[EI_OSABI])
    {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        default:
            printf("<unknown: %x>\n", h[EI_OSABI]);
    }

    printf("  ABI Version:                       %d\n", h[EI_ABIVERSION]);

    type = elf_get16(h + 16, data);
    printf("  Type:                              ");
    switch (type)
    {
        case ET_NONE: printf("NONE (No file type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown: %x>\n", type);
    }

    if (class == ELFCLASS32)
        entry = elf_get32(h + 24, data);
    else
        entry = elf_get64(h + 24, data);

    printf("  Entry point address:               0x%lx\n", entry);

    if (close(fd) == -1)
    {
        write(STDERR_FILENO, "Error: Can't close fd\n", 22);
        exit(98);
    }

    return (0);
}
