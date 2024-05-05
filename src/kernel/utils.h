#define asm __asm__

typedef unsigned char byte;

typedef byte u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef char i8;
typedef short i16;
typedef int i32;
typedef u32 size_t;

static byte inportb(u16 port);

void outportb(u16 port, u8 data);

u8 inportw(u16 port);

void outportw(u16 port, u16 data);

size_t strlen(const char *str);

void memset(void *dst, u8 value, size_t n);
