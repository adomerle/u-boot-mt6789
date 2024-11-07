// SPDX-License-Identifier: GPL-2.0
/*
 * TODO
 */
#include <asm/armv8/mmu.h>
int board_init(void)
{
	return 0;
}

/*
    DDR Memory 1     0x040000000 0x008200000
    BL31             0x048200000 0x000200000
    DDR Memory 2     0x048400000 0x027c00000
    TrustZone Mem    0x070000000 0x008800000
    DDR Memory 3     0x078800000 0x005200000
    TrustZone SHM    0x07da00000 0x000400000
    TrustZone SecMem 0x07de00000 0x000800000
    DDR Memory 4     0x07e600000 0x000600000
    GenieZone Mem    0x07ec00000 0x001200000
    DDR Memory 5     0x07fe00000 0x00f200000
    SCP IPC          0x08f000000 0x0005b0000
    DDR Memory 6     0x08f5b0000 0x00ffb0000
    SSPM IPC         0x09f560000 0x000110000
    DDR Memory 7     0x09f670000 0x000800000
    SSPM Mem         0x09fe70000 0x000180000
    DDR Memory 8     0x09fff0000 0x01fa10000
    SCP Mem          0x0bfa00000 0x000400000
    DDR Memory 9     0x0bfe00000 0x03e2d0000
    Framebuffer      0x0fe0d0000 0x001f2f000
    DDR Memory 10    0x0fffff000 0x100001000
*/

static struct mm_region emerald_mem_map[] = {
    {
        /* Periphs */
        .virt = 0x000000000UL,
        .phys = 0x000000000UL,
        .size = 0x020000000UL,
        .attrs = PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
			 PTE_BLOCK_NON_SHARE |
			 PTE_BLOCK_PXN | PTE_BLOCK_UXN
    }, {
		/* DDR Memory 1*/
		.virt = 0x040000000UL,
		.phys = 0x040000000UL,
		.size = 0x008200000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) | PTE_BLOCK_OUTER_SHARE,
	}, {
		/* Framebuffer */
		.virt = 0x0fe0d0000UL,
		.phys = 0x0fe0d0000UL,
		.size = 0x001f2f000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) | PTE_BLOCK_OUTER_SHARE,
	}, {
    }
};

struct mm_region *mem_map = emerald_mem_map;