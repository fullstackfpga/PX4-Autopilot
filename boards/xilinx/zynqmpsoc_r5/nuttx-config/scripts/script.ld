/****************************************************************************
 * boards/xilinx/zynqmpsoc_r5/nuttx-config/scripts/script.ld
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/* 
 * Xilinx ZynqMP R5 Memory Layout
 *
 * The ZynqMP R5 processor has the following memory regions:
 * - TCM (Tightly Coupled Memory): 128KB ATCM + 128KB BTCM
 * - OCM (On-Chip Memory): 256KB shared between A53 and R5
 * - DDR: Access to main system DDR (configured by bootloader)
 *
 * For this configuration, we'll use:
 * - ATCM: 128KB at 0x00000000 (for vectors and critical code)
 * - BTCM: 128KB at 0x00020000 (for data and stack)
 * - OCM:  256KB at 0xFFFC0000 (for additional storage)
 */

MEMORY
{
    /* Tightly Coupled Memory - Instruction (ATCM) */
    atcm (rx)  : ORIGIN = 0x00000000, LENGTH = 128K
    
    /* Tightly Coupled Memory - Data (BTCM) */
    btcm (rwx) : ORIGIN = 0x00020000, LENGTH = 128K
    
    /* On-Chip Memory (OCM) */
    ocm (rwx)  : ORIGIN = 0xFFFC0000, LENGTH = 256K
}

EXTERN(_vectors)
ENTRY(_stext)

SECTIONS
{
    /* Vector table and critical code in ATCM */
    .vectors : {
        _svectors = ABSOLUTE(.);
        *(.vectors)
        . = ALIGN(4);
        _evectors = ABSOLUTE(.);
    } > atcm
    
    /* Main text section in ATCM */
    .text : {
        _stext = ABSOLUTE(.);
        *(.text .text.*)
        *(.fixup)
        *(.gnu.warning)
        *(.rodata .rodata.*)
        *(.gnu.linkonce.t.*)
        *(.glue_7)
        *(.glue_7t)
        *(.got)
        *(.gcc_except_table)
        *(.gnu.linkonce.r.*)
        . = ALIGN(4);
        _etext = ABSOLUTE(.);
    } > atcm

    /* Constructor/destructor tables */
    .init_section : {
        _sinit = ABSOLUTE(.);
        *(.init_array .init_array.*)
        _einit = ABSOLUTE(.);
    } > atcm

    /* ARM exception handling */
    .ARM.extab : {
        *(.ARM.extab*)
    } > atcm

    __exidx_start = ABSOLUTE(.);
    .ARM.exidx : {
        *(.ARM.exidx*)
    } > atcm
    __exidx_end = ABSOLUTE(.);

    _eronly = ABSOLUTE(.);

    /* Data section in BTCM */
    .data : {
        _sdata = ABSOLUTE(.);
        *(.data .data.*)
        *(.gnu.linkonce.d.*)
        CONSTRUCTORS
        . = ALIGN(4);
        _edata = ABSOLUTE(.);
    } > btcm AT > atcm

    /* BSS section in BTCM */
    .bss : {
        _sbss = ABSOLUTE(.);
        *(.bss .bss.*)
        *(.gnu.linkonce.b.*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = ABSOLUTE(.);
    } > btcm

    /* Stack section in BTCM */
    .stack : {
        _sstack = ABSOLUTE(.);
        . = . + 0x4000;  /* 16KB stack */
        . = ALIGN(4);
        _estack = ABSOLUTE(.);
    } > btcm

    /* Heap section in OCM */
    .heap : {
        _sheap = ABSOLUTE(.);
        . = ORIGIN(ocm) + LENGTH(ocm);
        _eheap = ABSOLUTE(.);
    } > ocm

    /* Debug sections */
    .stab 0 : { *(.stab) }
    .stabstr 0 : { *(.stabstr) }
    .stab.excl 0 : { *(.stab.excl) }
    .stab.exclstr 0 : { *(.stab.exclstr) }
    .stab.index 0 : { *(.stab.index) }
    .stab.indexstr 0 : { *(.stab.indexstr) }
    .comment 0 : { *(.comment) }
    .debug_abbrev 0 : { *(.debug_abbrev) }
    .debug_info 0 : { *(.debug_info) }
    .debug_line 0 : { *(.debug_line) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    .debug_aranges 0 : { *(.debug_aranges) }
    .debug_str 0 : { *(.debug_str) }
    .debug_ranges 0 : { *(.debug_ranges) }
    .debug_loc 0 : { *(.debug_loc) }
    .debug_macinfo 0 : { *(.debug_macinfo) }
    .debug_pubtypes 0 : { *(.debug_pubtypes) }
    .debug_frame 0 : { *(.debug_frame) }
    .debug_types 0 : { *(.debug_types) }
    .debug_addr 0 : { *(.debug_addr) }
    .debug_line_str 0 : { *(.debug_line_str) }
    .debug_loclists 0 : { *(.debug_loclists) }
    .debug_rnglists 0 : { *(.debug_rnglists) }
}