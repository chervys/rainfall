//----- (080484B4) --------------------------------------------------------
char* __cdecl p(char* dest, char* s)
{
    char buf[4104]; // [esp+10h] [ebp-1008h] BYREF

    puts(s);
    read(0, buf, 0x1000u);
    *strchr(buf, 10) = 0;
    return strncpy(dest, buf, 0x14u);
}

//----- (0804851E) --------------------------------------------------------
char* __cdecl pp(char* dest)
{
    char src[20]; // [esp+28h] [ebp-30h] BYREF
    char v3[28]; // [esp+3Ch] [ebp-1Ch] BYREF

    p(src, " - ");
    p(v3, " - ");
    strcpy(dest, src);
    *(_WORD*)&dest[strlen(dest)] = unk_80486A4;
    return strcat(dest, v3);
}

//----- (080485A4) --------------------------------------------------------
int __cdecl main(int argc, const char** argv, const char** envp)
{
    char s[42]; // [esp+16h] [ebp-2Ah] BYREF

    pp(s);
    puts(s);
    return 0;
}
