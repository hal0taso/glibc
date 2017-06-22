/* ELF program property for Intel CET.
   Copyright (C) 2017 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef _SYS_CET_H
#define _SYS_CET_H	1

/* Add x86 feature with IBT and/or SHSTK bits to ELF program property
   if they are enabled.  Otherwise, contents in this header file are
   unused.  */

# ifdef __ASSEMBLER__

#  ifdef __LP64__
#   define __PROPERTY_ALIGN 3
#  else
#   define __PROPERTY_ALIGN 2
#  endif

#  ifdef __IBT__
	.pushsection ".note.gnu.property", "a"
	.p2align __PROPERTY_ALIGN
	.long 1f - 0f		/* name length.  */
	.long 5f - 1f		/* data length.  */
	/* NT_GNU_PROPERTY_TYPE_0.   */
	.long 5			/* note type.  */
0:
	.asciz "GNU"		/* vendor name.  */
1:
	.p2align __PROPERTY_ALIGN
	/* GNU_PROPERTY_X86_FEATURE_1_AND.  */
	.long 0xc0000002	/* pr_type.  */
	.long 4f - 3f		/* pr_datasz.  */
3:
	/* GNU_PROPERTY_X86_FEATURE_1_IBT.  */
	.long 0x1
4:
	.p2align __PROPERTY_ALIGN
5:
	.popsection
#  endif

#  ifdef __SHSTK__
	.pushsection ".note.gnu.property", "a"
	.p2align __PROPERTY_ALIGN
	.long 1f - 0f		/* name length.  */
	.long 5f - 1f		/* data length.  */
	/* NT_GNU_PROPERTY_TYPE_0.   */
	.long 5			/* note type.  */
0:
	.asciz "GNU"		/* vendor name.  */
1:
	.p2align __PROPERTY_ALIGN
	/* GNU_PROPERTY_X86_FEATURE_1_AND.  */
	.long 0xc0000002	/* pr_type.  */
	.long 4f - 3f		/* pr_datasz.  */
3:
	/* GNU_PROPERTY_X86_FEATURE_1_SHSTK.  */
	.long 0x2
4:
	.p2align __PROPERTY_ALIGN
5:
	.popsection
#  endif

# else

#  ifdef __LP64__
#   define __PROPERTY_ALIGN "3"
#  else
#   define __PROPERTY_ALIGN "2"
#  endif

#  ifdef __IBT__
  __asm ("\
	.pushsection \".note.gnu.property\", \"a\"\n\
	.p2align " __PROPERTY_ALIGN "\n\
	.long 1f - 0f		/* name length.  */\n\
	.long 5f - 1f		/* data length.  */\n\
	/* NT_GNU_PROPERTY_TYPE_0.   */\n\
	.long 5			/* note type.  */\n\
0:\n\
	.asciz \"GNU\"		/* vendor name.  */\n\
1:\n\
	.p2align " __PROPERTY_ALIGN "\n\
	/* GNU_PROPERTY_X86_FEATURE_1_AND.  */\n\
	.long 0xc0000002	/* pr_type.  */\n\
	.long 4f - 3f		/* pr_datasz.  */\n\
3:\n\
	/* GNU_PROPERTY_X86_FEATURE_1_IBT.  */\n\
	.long 0x1\n\
4:\n\
	.p2align " __PROPERTY_ALIGN "\n\
5:\n\
	.popsection");
#  endif

#  ifdef __SHSTK__
  __asm ("\
	.pushsection \".note.gnu.property\", \"a\"\n\
	.p2align " __PROPERTY_ALIGN "\n\
	.long 1f - 0f		/* name length.  */\n\
	.long 5f - 1f		/* data length.  */\n\
	/* NT_GNU_PROPERTY_TYPE_0.   */\n\
	.long 5			/* note type.  */\n\
0:\n\
	.asciz \"GNU\"		/* vendor name.  */\n\
1:\n\
	.p2align " __PROPERTY_ALIGN "\n\
	/* GNU_PROPERTY_X86_FEATURE_1_AND.  */\n\
	.long 0xc0000002	/* pr_type.  */\n\
	.long 4f - 3f		/* pr_datasz.  */\n\
3:\n\
	/* GNU_PROPERTY_X86_FEATURE_1_SHSTK.  */\n\
	.long 0x2\n\
4:\n\
	.p2align " __PROPERTY_ALIGN "\n\
5:\n\
	.popsection");
#  endif

# endif

#endif	/* _SYS_CET_H */
