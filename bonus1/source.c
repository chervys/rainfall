int __cdecl main(int argc, const char** argv, const char** envp)
{
    char dest[40]; // [esp+14h] [ebp-2Ch] BYREF
    int v5; // [esp+3Ch] [ebp-4h]

    v5 = atoi(argv[1]);
    if (v5 > 9)
        return 1;
    memcpy(dest, argv[2], 4 * v5);
    if (v5 == 1464814662)
        execl("/bin/sh", "sh", 0);
    return 0;
}
