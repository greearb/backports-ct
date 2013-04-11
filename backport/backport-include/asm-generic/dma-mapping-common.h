#ifndef __BACKPORT_ASM_GENERIC_DMA_MAPPING_COMMON_H
#define __BACKPORT_ASM_GENERIC_DMA_MAPPING_COMMON_H
#include_next <asm-generic/dma-mapping-common.h>
#include <linux/version.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(3,6,0)

#define dma_common_get_sgtable LINUX_BACKPORT(dma_common_get_sgtable)
int
dma_common_get_sgtable(struct device *dev, struct sg_table *sgt,
		       void *cpu_addr, dma_addr_t dma_addr, size_t size);

#define dma_get_sgtable_attrs LINUX_BACKPORT(dma_get_sgtable_attrs)
struct dma_attrs;
static inline int
dma_get_sgtable_attrs(struct device *dev, struct sg_table *sgt, void *cpu_addr,
		      dma_addr_t dma_addr, size_t size, struct dma_attrs *attrs)
{
	return dma_common_get_sgtable(dev, sgt, cpu_addr, dma_addr, size);
}

#define dma_get_sgtable(d, t, v, h, s) dma_get_sgtable_attrs(d, t, v, h, s, NULL)
#endif

#endif /* __BACKPORT_ASM_GENERIC_DMA_MAPPING_COMMON_H */
