/*
   Copyright 2009-2013 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* This was compiled from a trivial program just to test whether GDB
   will add const variable to partial symbol.

  static const int const_var = 6;

  int main(){
          return 0;
  }

  Then it was compiled with:
	
	gcc -g -O1
  
  We could see the DIE of 'const_var' is as following:
  <1><25>: Abbrev Number: 2 (DW_TAG_variable)
     <26>   DW_AT_name        : var
     <2a>   DW_AT_decl_file   : 1
     <2b>   DW_AT_decl_line   : 1
     <2c>   DW_AT_type        : <0x31>
     <30>   DW_AT_const_value : 3

  We need add it to partial symbol table.

*/

	.file	"const-var.c"
	.text
.Ltext0:
.Letext0:
	.file 1 "/tmp/const-var.c"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x36
	.value	0x2
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF0
	.byte	0x1
	.long	.LASF1
	.long	.Ltext0
	.long	.Letext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF2
	.byte	0x1
	.byte	0x1
	.long	0x2d
	.byte	0x6
	.uleb128 0x3
	.long	0x32
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF0:
	.string	"GNU C 4.6.3"
.LASF1:
	.string	"/tmp/const-var.c"
.LASF2:
	.string	"const_var"
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
