#include "sdb_internal.h"

size_t sdb_stack_mark(sdb_context *ctx)
{
    size_t i;
    ctx->stack_mark = &i;
    ctx->stack_max_usage = 0;
    return (size_t)ctx->stack_mark;
}

size_t sdb_stack_touch(sdb_context *ctx)
{
    size_t p;
    ctx->stack_top = (size_t)(ctx->stack_mark - &p);
    if (ctx->stack_top > ctx->stack_max_usage) {
        ctx->stack_max_usage = ctx->stack_top;
    }
    return ctx->stack_top;
}

size_t sdb_stack_max_usage(const sdb_context *ctx)
{
    return ctx->stack_max_usage;
}

