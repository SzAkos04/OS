#include "timer.h"

#include "irq.h"
#include "isr.h"
#include "utils.h"

#define PIT_CHANNEL_0 0x40
#define PIT_CONTROL_REG 0x43

#define PIT_MASK 0xFF
#define PIT_SET 0x36

#define PIT_FREQ 1193181
#define TIMER_FREQ 363

#define DIV_OF_FREQ(_f) (PIT_FREQ / (_f))
#define FREQ_OF_DIV(_d) (PIT_FREQ / (_d))
#define REAL_FREQ_OF_FREQ(_f) (FREQ_OF_DIV(DIV_OF_FREQ((_f))))

static struct {
    uint32_t frequency;
    uint32_t divisor;
    uint32_t ticks;
} state;

uint32_t timer_get(void) { return state.ticks; }

static void timer_handler(struct Registers *regs) {
    state.ticks++;
    outportb(0x20, 0x20);
}

void timer_init(void) {
    const uint32_t freq = REAL_FREQ_OF_FREQ(TIMER_FREQ);
    state.frequency = freq;
    state.divisor = DIV_OF_FREQ(freq);
    state.ticks = 0;

    outportb(PIT_CONTROL_REG, PIT_SET);

    uint16_t divisor = (uint16_t)(PIT_FREQ / TIMER_FREQ);
    outportb(PIT_CHANNEL_0, divisor & PIT_MASK);

    // BUG: If i comment out the next two lines, the rendering returns, so the
    // problem must be somewhere here
    outportb(PIT_CHANNEL_0, (divisor >> 8) & PIT_MASK);

    irq_install(0, timer_handler);
}
