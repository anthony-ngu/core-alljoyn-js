#ifndef _DUK_CUSTOM_H
#define _DUK_CUSTOM_H
/**
 * @file
 */
/******************************************************************************
 * Copyright (c) 2014, AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

/*
 * Force alignment for testing
 */
#ifdef DUK_FORCE_ALIGNED_ACCESS
#undef DUK_USE_UNALIGNED_ACCESSES_POSSIBLE
#undef DUK_USE_HASHBYTES_UNALIGNED_U32_ACCESS
#undef DUK_USE_HOBJECT_UNALIGNED_LAYOUT
#endif

#if DUK_VERSION < 10100
#define duk_push_c_lightfunc(c, f, a, x, y) duk_push_c_function(c, f, a)
#endif

#define DUK_OPT_HEAPPTR_ENC16(p) AJS_EncodePtr16(p) 
#define DUK_OPT_HEAPPTR_DEC16(x) AJS_DecodePtr16(x)
#define DUK_OPT_EXTSTR_INTERN_CHECK(p,l) AJS_ExternalStringCheck(p,l)
#define DUK_OPT_EXTSTR_FREE(p) AJS_ExternalStringFree(p)

duk_uint16_t AJS_EncodePtr16(void *p);

void* AJS_DecodePtr16(duk_uint16_t x);

const void* AJS_ExternalStringCheck(const void *ptr, duk_size_t len);

void AJS_ExternalStringFree(const void *ptr);

#endif
