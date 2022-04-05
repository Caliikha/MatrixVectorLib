
run:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 2a 2f 00 00    	pushq  0x2f2a(%rip)        # 3f50 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 2b 2f 00 00 	bnd jmpq *0x2f2b(%rip)        # 3f58 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	pushq  $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmpq 1020 <.plt>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	pushq  $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmpq 1020 <.plt>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	pushq  $0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmpq 1020 <.plt>
    107f:	90                   	nop
    1080:	f3 0f 1e fa          	endbr64 
    1084:	68 05 00 00 00       	pushq  $0x5
    1089:	f2 e9 91 ff ff ff    	bnd jmpq 1020 <.plt>
    108f:	90                   	nop
    1090:	f3 0f 1e fa          	endbr64 
    1094:	68 06 00 00 00       	pushq  $0x6
    1099:	f2 e9 81 ff ff ff    	bnd jmpq 1020 <.plt>
    109f:	90                   	nop
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	68 07 00 00 00       	pushq  $0x7
    10a9:	f2 e9 71 ff ff ff    	bnd jmpq 1020 <.plt>
    10af:	90                   	nop
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	68 08 00 00 00       	pushq  $0x8
    10b9:	f2 e9 61 ff ff ff    	bnd jmpq 1020 <.plt>
    10bf:	90                   	nop
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	68 09 00 00 00       	pushq  $0x9
    10c9:	f2 e9 51 ff ff ff    	bnd jmpq 1020 <.plt>
    10cf:	90                   	nop
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	68 0a 00 00 00       	pushq  $0xa
    10d9:	f2 e9 41 ff ff ff    	bnd jmpq 1020 <.plt>
    10df:	90                   	nop
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	68 0b 00 00 00       	pushq  $0xb
    10e9:	f2 e9 31 ff ff ff    	bnd jmpq 1020 <.plt>
    10ef:	90                   	nop
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	68 0c 00 00 00       	pushq  $0xc
    10f9:	f2 e9 21 ff ff ff    	bnd jmpq 1020 <.plt>
    10ff:	90                   	nop
    1100:	f3 0f 1e fa          	endbr64 
    1104:	68 0d 00 00 00       	pushq  $0xd
    1109:	f2 e9 11 ff ff ff    	bnd jmpq 1020 <.plt>
    110f:	90                   	nop

Disassembly of section .plt.got:

0000000000001110 <__cxa_finalize@plt>:
    1110:	f3 0f 1e fa          	endbr64 
    1114:	f2 ff 25 b5 2e 00 00 	bnd jmpq *0x2eb5(%rip)        # 3fd0 <__cxa_finalize@GLIBC_2.2.5>
    111b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001120 <sqrt@plt>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	f2 ff 25 35 2e 00 00 	bnd jmpq *0x2e35(%rip)        # 3f60 <sqrt@GLIBC_2.2.5>
    112b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001130 <__cxa_atexit@plt>:
    1130:	f3 0f 1e fa          	endbr64 
    1134:	f2 ff 25 2d 2e 00 00 	bnd jmpq *0x2e2d(%rip)        # 3f68 <__cxa_atexit@GLIBC_2.2.5>
    113b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001140 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	f2 ff 25 25 2e 00 00 	bnd jmpq *0x2e25(%rip)        # 3f70 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GLIBCXX_3.4>
    114b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001150 <_ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode@plt>:
    1150:	f3 0f 1e fa          	endbr64 
    1154:	f2 ff 25 1d 2e 00 00 	bnd jmpq *0x2e1d(%rip)        # 3f78 <_ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode@GLIBCXX_3.4>
    115b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001160 <__stack_chk_fail@plt>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	f2 ff 25 15 2e 00 00 	bnd jmpq *0x2e15(%rip)        # 3f80 <__stack_chk_fail@GLIBC_2.4>
    116b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>:
    1170:	f3 0f 1e fa          	endbr64 
    1174:	f2 ff 25 0d 2e 00 00 	bnd jmpq *0x2e0d(%rip)        # 3f88 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@GLIBCXX_3.4.9>
    117b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001180 <_ZNSt14basic_ofstreamIcSt11char_traitsIcEE5closeEv@plt>:
    1180:	f3 0f 1e fa          	endbr64 
    1184:	f2 ff 25 05 2e 00 00 	bnd jmpq *0x2e05(%rip)        # 3f90 <_ZNSt14basic_ofstreamIcSt11char_traitsIcEE5closeEv@GLIBCXX_3.4>
    118b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001190 <_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@plt>:
    1190:	f3 0f 1e fa          	endbr64 
    1194:	f2 ff 25 fd 2d 00 00 	bnd jmpq *0x2dfd(%rip)        # 3f98 <_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@GLIBCXX_3.4>
    119b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011a0 <_ZNSt8ios_base4InitC1Ev@plt>:
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	f2 ff 25 f5 2d 00 00 	bnd jmpq *0x2df5(%rip)        # 3fa0 <_ZNSt8ios_base4InitC1Ev@GLIBCXX_3.4>
    11ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011b0 <_ZNSo9_M_insertIdEERSoT_@plt>:
    11b0:	f3 0f 1e fa          	endbr64 
    11b4:	f2 ff 25 ed 2d 00 00 	bnd jmpq *0x2ded(%rip)        # 3fa8 <_ZNSo9_M_insertIdEERSoT_@GLIBCXX_3.4.9>
    11bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011c0 <_ZNSolsEi@plt>:
    11c0:	f3 0f 1e fa          	endbr64 
    11c4:	f2 ff 25 e5 2d 00 00 	bnd jmpq *0x2de5(%rip)        # 3fb0 <_ZNSolsEi@GLIBCXX_3.4>
    11cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011d0 <pow@plt>:
    11d0:	f3 0f 1e fa          	endbr64 
    11d4:	f2 ff 25 dd 2d 00 00 	bnd jmpq *0x2ddd(%rip)        # 3fb8 <pow@GLIBC_2.29>
    11db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011e0 <_Unwind_Resume@plt>:
    11e0:	f3 0f 1e fa          	endbr64 
    11e4:	f2 ff 25 d5 2d 00 00 	bnd jmpq *0x2dd5(%rip)        # 3fc0 <_Unwind_Resume@GCC_3.0>
    11eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011f0 <_ZNSi10_M_extractIfEERSiRT_@plt>:
    11f0:	f3 0f 1e fa          	endbr64 
    11f4:	f2 ff 25 cd 2d 00 00 	bnd jmpq *0x2dcd(%rip)        # 3fc8 <_ZNSi10_M_extractIfEERSiRT_@GLIBCXX_3.4.9>
    11fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001200 <main.cold>:
    1200:	48 8b 7c 24 28       	mov    0x28(%rsp),%rdi
    1205:	e8 86 ff ff ff       	callq  1190 <_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@plt>
    120a:	48 89 ef             	mov    %rbp,%rdi
    120d:	e8 ce ff ff ff       	callq  11e0 <_Unwind_Resume@plt>
    1212:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    1219:	00 00 00 
    121c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001220 <main>:
    1220:	f3 0f 1e fa          	endbr64 
    1224:	41 57                	push   %r15
    1226:	b9 20 00 00 00       	mov    $0x20,%ecx
    122b:	ba 10 00 00 00       	mov    $0x10,%edx
    1230:	48 8d 35 29 0e 00 00 	lea    0xe29(%rip),%rsi        # 2060 <_IO_stdin_used+0x60>
    1237:	41 56                	push   %r14
    1239:	41 55                	push   %r13
    123b:	41 54                	push   %r12
    123d:	55                   	push   %rbp
    123e:	53                   	push   %rbx
    123f:	48 81 ec 78 03 00 00 	sub    $0x378,%rsp
    1246:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    124d:	00 00 
    124f:	48 89 84 24 68 03 00 	mov    %rax,0x368(%rsp)
    1256:	00 
    1257:	31 c0                	xor    %eax,%eax
    1259:	48 8d 7c 24 50       	lea    0x50(%rsp),%rdi
    125e:	48 89 7c 24 20       	mov    %rdi,0x20(%rsp)
    1263:	49 89 ff             	mov    %rdi,%r15
    1266:	f3 48 a5             	rep movsq %ds:(%rsi),%es:(%rdi)
    1269:	8b 06                	mov    (%rsi),%eax
    126b:	48 8d 35 b9 0d 00 00 	lea    0xdb9(%rip),%rsi        # 202b <_IO_stdin_used+0x2b>
    1272:	89 07                	mov    %eax,(%rdi)
    1274:	48 8d 84 24 60 01 00 	lea    0x160(%rsp),%rax
    127b:	00 
    127c:	48 89 c3             	mov    %rax,%rbx
    127f:	48 89 c7             	mov    %rax,%rdi
    1282:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
    1287:	e8 c4 fe ff ff       	callq  1150 <_ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode@plt>
    128c:	48 8d 35 ae 0d 00 00 	lea    0xdae(%rip),%rsi        # 2041 <_IO_stdin_used+0x41>
    1293:	48 89 df             	mov    %rbx,%rdi
    1296:	e8 a5 fe ff ff       	callq  1140 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    129b:	4c 89 fe             	mov    %r15,%rsi
    129e:	48 89 df             	mov    %rbx,%rdi
    12a1:	e8 ea 06 00 00       	callq  1990 <_Z6printVI7Vector3ERSt14basic_ofstreamIcSt11char_traitsIcEES5_RKT_>
    12a6:	48 8d b4 24 84 00 00 	lea    0x84(%rsp),%rsi
    12ad:	00 
    12ae:	48 89 df             	mov    %rbx,%rdi
    12b1:	e8 da 06 00 00       	callq  1990 <_Z6printVI7Vector3ERSt14basic_ofstreamIcSt11char_traitsIcEES5_RKT_>
    12b6:	48 8d b4 24 b8 00 00 	lea    0xb8(%rsp),%rsi
    12bd:	00 
    12be:	48 89 df             	mov    %rbx,%rdi
    12c1:	e8 ca 06 00 00       	callq  1990 <_Z6printVI7Vector3ERSt14basic_ofstreamIcSt11char_traitsIcEES5_RKT_>
    12c6:	48 8d b4 24 ec 00 00 	lea    0xec(%rsp),%rsi
    12cd:	00 
    12ce:	48 89 df             	mov    %rbx,%rdi
    12d1:	e8 ba 06 00 00       	callq  1990 <_Z6printVI7Vector3ERSt14basic_ofstreamIcSt11char_traitsIcEES5_RKT_>
    12d6:	48 8d b4 24 20 01 00 	lea    0x120(%rsp),%rsi
    12dd:	00 
    12de:	48 89 df             	mov    %rbx,%rdi
    12e1:	e8 aa 06 00 00       	callq  1990 <_Z6printVI7Vector3ERSt14basic_ofstreamIcSt11char_traitsIcEES5_RKT_>
    12e6:	c7 44 24 30 00 00 00 	movl   $0x0,0x30(%rsp)
    12ed:	00 
    12ee:	c7 44 24 34 00 00 00 	movl   $0x0,0x34(%rsp)
    12f5:	00 
    12f6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    12fd:	00 00 00 
    1300:	44 8b 64 24 30       	mov    0x30(%rsp),%r12d
    1305:	b8 cd cc cc cc       	mov    $0xcccccccd,%eax
    130a:	48 8b 5c 24 20       	mov    0x20(%rsp),%rbx
    130f:	31 ed                	xor    %ebp,%ebp
    1311:	4c 89 e1             	mov    %r12,%rcx
    1314:	4c 0f af e0          	imul   %rax,%r12
    1318:	49 c1 ec 23          	shr    $0x23,%r12
    131c:	43 8d 04 a4          	lea    (%r12,%r12,4),%eax
    1320:	01 c0                	add    %eax,%eax
    1322:	29 c1                	sub    %eax,%ecx
    1324:	41 89 cc             	mov    %ecx,%r12d
    1327:	4c 8b 74 24 20       	mov    0x20(%rsp),%r14
    132c:	45 31 ff             	xor    %r15d,%r15d
    132f:	45 31 ed             	xor    %r13d,%r13d
    1332:	44 39 fd             	cmp    %r15d,%ebp
    1335:	0f 84 7d 01 00 00    	je     14b8 <main+0x298>
    133b:	41 8b 56 30          	mov    0x30(%r14),%edx
    133f:	66 0f ef c0          	pxor   %xmm0,%xmm0
    1343:	66 0f ef c9          	pxor   %xmm1,%xmm1
    1347:	66 0f ef ed          	pxor   %xmm5,%xmm5
    134b:	f3 41 0f 10 26       	movss  (%r14),%xmm4
    1350:	f3 41 0f 10 5e 04    	movss  0x4(%r14),%xmm3
    1356:	66 0f ef ff          	pxor   %xmm7,%xmm7
    135a:	f3 48 0f 2a c2       	cvtsi2ss %rdx,%xmm0
    135f:	f3 0f 5c 23          	subss  (%rbx),%xmm4
    1363:	f3 0f 59 05 f9 0d 00 	mulss  0xdf9(%rip),%xmm0        # 2164 <_IO_stdin_used+0x164>
    136a:	00 
    136b:	f3 0f 5c 5b 04       	subss  0x4(%rbx),%xmm3
    1370:	f3 41 0f 10 56 08    	movss  0x8(%r14),%xmm2
    1376:	f3 0f 5c 53 08       	subss  0x8(%rbx),%xmm2
    137b:	f3 0f 5a cc          	cvtss2sd %xmm4,%xmm1
    137f:	f2 0f 59 c9          	mulsd  %xmm1,%xmm1
    1383:	f3 0f 5a eb          	cvtss2sd %xmm3,%xmm5
    1387:	f2 0f 59 ed          	mulsd  %xmm5,%xmm5
    138b:	f3 0f 5a f8          	cvtss2sd %xmm0,%xmm7
    138f:	66 0f ef c0          	pxor   %xmm0,%xmm0
    1393:	f2 0f 11 7c 24 08    	movsd  %xmm7,0x8(%rsp)
    1399:	66 0f ef ff          	pxor   %xmm7,%xmm7
    139d:	f3 0f 5a c2          	cvtss2sd %xmm2,%xmm0
    13a1:	f2 0f 59 c0          	mulsd  %xmm0,%xmm0
    13a5:	f2 0f 58 cd          	addsd  %xmm5,%xmm1
    13a9:	f2 0f 58 c1          	addsd  %xmm1,%xmm0
    13ad:	66 0f 2e f8          	ucomisd %xmm0,%xmm7
    13b1:	66 0f 28 c8          	movapd %xmm0,%xmm1
    13b5:	f2 0f 51 c9          	sqrtsd %xmm1,%xmm1
    13b9:	0f 87 43 02 00 00    	ja     1602 <main+0x3e2>
    13bf:	48 8b 05 aa 0d 00 00 	mov    0xdaa(%rip),%rax        # 2170 <_IO_stdin_used+0x170>
    13c6:	66 0f ef c0          	pxor   %xmm0,%xmm0
    13ca:	f3 0f 11 54 24 1c    	movss  %xmm2,0x1c(%rsp)
    13d0:	f2 0f 5a c1          	cvtsd2ss %xmm1,%xmm0
    13d4:	f3 0f 11 5c 24 18    	movss  %xmm3,0x18(%rsp)
    13da:	f3 0f 5a c0          	cvtss2sd %xmm0,%xmm0
    13de:	66 48 0f 6e c8       	movq   %rax,%xmm1
    13e3:	f3 0f 11 64 24 14    	movss  %xmm4,0x14(%rsp)
    13e9:	e8 e2 fd ff ff       	callq  11d0 <pow@plt>
    13ee:	f2 0f 10 74 24 08    	movsd  0x8(%rsp),%xmm6
    13f4:	8b 53 30             	mov    0x30(%rbx),%edx
    13f7:	f3 0f 10 5c 24 18    	movss  0x18(%rsp),%xmm3
    13fd:	f3 0f 10 54 24 1c    	movss  0x1c(%rsp),%xmm2
    1403:	f2 0f 5e f0          	divsd  %xmm0,%xmm6
    1407:	f3 0f 10 64 24 14    	movss  0x14(%rsp),%xmm4
    140d:	66 0f ef c0          	pxor   %xmm0,%xmm0
    1411:	f2 0f 5a c6          	cvtsd2ss %xmm6,%xmm0
    1415:	f3 0f 59 d8          	mulss  %xmm0,%xmm3
    1419:	f3 0f 59 d0          	mulss  %xmm0,%xmm2
    141d:	f3 0f 58 5b 1c       	addss  0x1c(%rbx),%xmm3
    1422:	f3 0f 59 e0          	mulss  %xmm0,%xmm4
    1426:	66 0f ef c0          	pxor   %xmm0,%xmm0
    142a:	f3 0f 58 53 20       	addss  0x20(%rbx),%xmm2
    142f:	f3 48 0f 2a c2       	cvtsi2ss %rdx,%xmm0
    1434:	f3 0f 59 05 2c 0d 00 	mulss  0xd2c(%rip),%xmm0        # 2168 <_IO_stdin_used+0x168>
    143b:	00 
    143c:	f3 0f 58 63 18       	addss  0x18(%rbx),%xmm4
    1441:	f3 0f 11 5b 1c       	movss  %xmm3,0x1c(%rbx)
    1446:	f3 0f 11 53 20       	movss  %xmm2,0x20(%rbx)
    144b:	f3 0f 10 13          	movss  (%rbx),%xmm2
    144f:	f3 0f 11 63 18       	movss  %xmm4,0x18(%rbx)
    1454:	f3 41 0f 10 0e       	movss  (%r14),%xmm1
    1459:	0f 28 d8             	movaps %xmm0,%xmm3
    145c:	f3 0f 58 d9          	addss  %xmm1,%xmm3
    1460:	0f 2f da             	comiss %xmm2,%xmm3
    1463:	72 53                	jb     14b8 <main+0x298>
    1465:	f3 0f 5c c8          	subss  %xmm0,%xmm1
    1469:	0f 2f d1             	comiss %xmm1,%xmm2
    146c:	76 4a                	jbe    14b8 <main+0x298>
    146e:	f3 41 0f 10 4e 04    	movss  0x4(%r14),%xmm1
    1474:	0f 28 d8             	movaps %xmm0,%xmm3
    1477:	f3 0f 10 53 04       	movss  0x4(%rbx),%xmm2
    147c:	f3 0f 58 d9          	addss  %xmm1,%xmm3
    1480:	0f 2f da             	comiss %xmm2,%xmm3
    1483:	72 33                	jb     14b8 <main+0x298>
    1485:	f3 0f 5c c8          	subss  %xmm0,%xmm1
    1489:	0f 2f d1             	comiss %xmm1,%xmm2
    148c:	76 2a                	jbe    14b8 <main+0x298>
    148e:	f3 41 0f 10 4e 08    	movss  0x8(%r14),%xmm1
    1494:	0f 28 d8             	movaps %xmm0,%xmm3
    1497:	f3 0f 10 53 08       	movss  0x8(%rbx),%xmm2
    149c:	f3 0f 58 d9          	addss  %xmm1,%xmm3
    14a0:	0f 2f da             	comiss %xmm2,%xmm3
    14a3:	72 13                	jb     14b8 <main+0x298>
    14a5:	f3 0f 5c c8          	subss  %xmm0,%xmm1
    14a9:	ba 01 00 00 00       	mov    $0x1,%edx
    14ae:	0f 2e d1             	ucomiss %xmm1,%xmm2
    14b1:	44 0f 47 ea          	cmova  %edx,%r13d
    14b5:	0f 1f 00             	nopl   (%rax)
    14b8:	41 83 c7 01          	add    $0x1,%r15d
    14bc:	49 83 c6 34          	add    $0x34,%r14
    14c0:	41 83 ff 05          	cmp    $0x5,%r15d
    14c4:	0f 85 68 fe ff ff    	jne    1332 <main+0x112>
    14ca:	45 84 ed             	test   %r13b,%r13b
    14cd:	75 0a                	jne    14d9 <main+0x2b9>
    14cf:	83 7b 30 63          	cmpl   $0x63,0x30(%rbx)
    14d3:	0f 86 b7 00 00 00    	jbe    1590 <main+0x370>
    14d9:	45 85 e4             	test   %r12d,%r12d
    14dc:	0f 84 8e 00 00 00    	je     1570 <main+0x350>
    14e2:	83 c5 01             	add    $0x1,%ebp
    14e5:	48 83 c3 34          	add    $0x34,%rbx
    14e9:	83 fd 05             	cmp    $0x5,%ebp
    14ec:	0f 85 35 fe ff ff    	jne    1327 <main+0x107>
    14f2:	83 44 24 30 01       	addl   $0x1,0x30(%rsp)
    14f7:	8b 44 24 30          	mov    0x30(%rsp),%eax
    14fb:	3d e8 03 00 00       	cmp    $0x3e8,%eax
    1500:	0f 85 fa fd ff ff    	jne    1300 <main+0xe0>
    1506:	8b 74 24 34          	mov    0x34(%rsp),%esi
    150a:	48 8d 3d 2f 2b 00 00 	lea    0x2b2f(%rip),%rdi        # 4040 <_ZSt4cout@@GLIBCXX_3.4>
    1511:	e8 aa fc ff ff       	callq  11c0 <_ZNSolsEi@plt>
    1516:	48 89 c7             	mov    %rax,%rdi
    1519:	48 8d 74 24 4f       	lea    0x4f(%rsp),%rsi
    151e:	ba 01 00 00 00       	mov    $0x1,%edx
    1523:	c6 44 24 4f 0a       	movb   $0xa,0x4f(%rsp)
    1528:	e8 43 fc ff ff       	callq  1170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>
    152d:	48 8b 5c 24 28       	mov    0x28(%rsp),%rbx
    1532:	48 89 df             	mov    %rbx,%rdi
    1535:	e8 46 fc ff ff       	callq  1180 <_ZNSt14basic_ofstreamIcSt11char_traitsIcEE5closeEv@plt>
    153a:	48 89 df             	mov    %rbx,%rdi
    153d:	e8 4e fc ff ff       	callq  1190 <_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@plt>
    1542:	48 8b 84 24 68 03 00 	mov    0x368(%rsp),%rax
    1549:	00 
    154a:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1551:	00 00 
    1553:	0f 85 e3 00 00 00    	jne    163c <main+0x41c>
    1559:	48 81 c4 78 03 00 00 	add    $0x378,%rsp
    1560:	31 c0                	xor    %eax,%eax
    1562:	5b                   	pop    %rbx
    1563:	5d                   	pop    %rbp
    1564:	41 5c                	pop    %r12
    1566:	41 5d                	pop    %r13
    1568:	41 5e                	pop    %r14
    156a:	41 5f                	pop    %r15
    156c:	c3                   	retq   
    156d:	0f 1f 00             	nopl   (%rax)
    1570:	48 8b 7c 24 28       	mov    0x28(%rsp),%rdi
    1575:	48 89 de             	mov    %rbx,%rsi
    1578:	e8 13 04 00 00       	callq  1990 <_Z6printVI7Vector3ERSt14basic_ofstreamIcSt11char_traitsIcEES5_RKT_>
    157d:	83 44 24 34 01       	addl   $0x1,0x34(%rsp)
    1582:	e9 5b ff ff ff       	jmpq   14e2 <main+0x2c2>
    1587:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    158e:	00 00 
    1590:	f3 0f 10 53 18       	movss  0x18(%rbx),%xmm2
    1595:	f3 0f 10 4b 1c       	movss  0x1c(%rbx),%xmm1
    159a:	c7 43 18 00 00 00 00 	movl   $0x0,0x18(%rbx)
    15a1:	f3 0f 10 43 20       	movss  0x20(%rbx),%xmm0
    15a6:	f3 0f 58 53 24       	addss  0x24(%rbx),%xmm2
    15ab:	c7 43 1c 00 00 00 00 	movl   $0x0,0x1c(%rbx)
    15b2:	f3 0f 58 53 0c       	addss  0xc(%rbx),%xmm2
    15b7:	f3 0f 58 4b 28       	addss  0x28(%rbx),%xmm1
    15bc:	c7 43 20 00 00 00 00 	movl   $0x0,0x20(%rbx)
    15c3:	f3 0f 58 4b 10       	addss  0x10(%rbx),%xmm1
    15c8:	f3 0f 58 43 2c       	addss  0x2c(%rbx),%xmm0
    15cd:	f3 0f 58 43 14       	addss  0x14(%rbx),%xmm0
    15d2:	f3 0f 11 53 0c       	movss  %xmm2,0xc(%rbx)
    15d7:	f3 0f 58 13          	addss  (%rbx),%xmm2
    15db:	f3 0f 11 4b 10       	movss  %xmm1,0x10(%rbx)
    15e0:	f3 0f 58 4b 04       	addss  0x4(%rbx),%xmm1
    15e5:	f3 0f 11 43 14       	movss  %xmm0,0x14(%rbx)
    15ea:	f3 0f 58 43 08       	addss  0x8(%rbx),%xmm0
    15ef:	f3 0f 11 13          	movss  %xmm2,(%rbx)
    15f3:	f3 0f 11 4b 04       	movss  %xmm1,0x4(%rbx)
    15f8:	f3 0f 11 43 08       	movss  %xmm0,0x8(%rbx)
    15fd:	e9 d7 fe ff ff       	jmpq   14d9 <main+0x2b9>
    1602:	f2 0f 11 4c 24 38    	movsd  %xmm1,0x38(%rsp)
    1608:	f3 0f 11 54 24 1c    	movss  %xmm2,0x1c(%rsp)
    160e:	f3 0f 11 5c 24 18    	movss  %xmm3,0x18(%rsp)
    1614:	f3 0f 11 64 24 14    	movss  %xmm4,0x14(%rsp)
    161a:	e8 01 fb ff ff       	callq  1120 <sqrt@plt>
    161f:	f2 0f 10 4c 24 38    	movsd  0x38(%rsp),%xmm1
    1625:	f3 0f 10 54 24 1c    	movss  0x1c(%rsp),%xmm2
    162b:	f3 0f 10 5c 24 18    	movss  0x18(%rsp),%xmm3
    1631:	f3 0f 10 64 24 14    	movss  0x14(%rsp),%xmm4
    1637:	e9 83 fd ff ff       	jmpq   13bf <main+0x19f>
    163c:	e8 1f fb ff ff       	callq  1160 <__stack_chk_fail@plt>
    1641:	f3 0f 1e fa          	endbr64 
    1645:	48 89 c5             	mov    %rax,%rbp
    1648:	e9 b3 fb ff ff       	jmpq   1200 <main.cold>
    164d:	0f 1f 00             	nopl   (%rax)

0000000000001650 <_GLOBAL__sub_I__ZNK9Matrix2x29printmtrxEv>:
    1650:	f3 0f 1e fa          	endbr64 
    1654:	48 83 ec 08          	sub    $0x8,%rsp
    1658:	48 8d 3d 32 2d 00 00 	lea    0x2d32(%rip),%rdi        # 4391 <_ZStL8__ioinit>
    165f:	e8 3c fb ff ff       	callq  11a0 <_ZNSt8ios_base4InitC1Ev@plt>
    1664:	48 8b 3d 8d 29 00 00 	mov    0x298d(%rip),%rdi        # 3ff8 <_ZNSt8ios_base4InitD1Ev@GLIBCXX_3.4>
    166b:	48 83 c4 08          	add    $0x8,%rsp
    166f:	48 8d 15 92 29 00 00 	lea    0x2992(%rip),%rdx        # 4008 <__dso_handle>
    1676:	48 8d 35 14 2d 00 00 	lea    0x2d14(%rip),%rsi        # 4391 <_ZStL8__ioinit>
    167d:	e9 ae fa ff ff       	jmpq   1130 <__cxa_atexit@plt>
    1682:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    1689:	00 00 00 
    168c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001690 <_start>:
    1690:	f3 0f 1e fa          	endbr64 
    1694:	31 ed                	xor    %ebp,%ebp
    1696:	49 89 d1             	mov    %rdx,%r9
    1699:	5e                   	pop    %rsi
    169a:	48 89 e2             	mov    %rsp,%rdx
    169d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    16a1:	50                   	push   %rax
    16a2:	54                   	push   %rsp
    16a3:	4c 8d 05 76 04 00 00 	lea    0x476(%rip),%r8        # 1b20 <__libc_csu_fini>
    16aa:	48 8d 0d ff 03 00 00 	lea    0x3ff(%rip),%rcx        # 1ab0 <__libc_csu_init>
    16b1:	48 8d 3d 68 fb ff ff 	lea    -0x498(%rip),%rdi        # 1220 <main>
    16b8:	ff 15 22 29 00 00    	callq  *0x2922(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    16be:	f4                   	hlt    
    16bf:	90                   	nop

00000000000016c0 <deregister_tm_clones>:
    16c0:	48 8d 3d 51 29 00 00 	lea    0x2951(%rip),%rdi        # 4018 <__TMC_END__>
    16c7:	48 8d 05 4a 29 00 00 	lea    0x294a(%rip),%rax        # 4018 <__TMC_END__>
    16ce:	48 39 f8             	cmp    %rdi,%rax
    16d1:	74 15                	je     16e8 <deregister_tm_clones+0x28>
    16d3:	48 8b 05 fe 28 00 00 	mov    0x28fe(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    16da:	48 85 c0             	test   %rax,%rax
    16dd:	74 09                	je     16e8 <deregister_tm_clones+0x28>
    16df:	ff e0                	jmpq   *%rax
    16e1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    16e8:	c3                   	retq   
    16e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000016f0 <register_tm_clones>:
    16f0:	48 8d 3d 21 29 00 00 	lea    0x2921(%rip),%rdi        # 4018 <__TMC_END__>
    16f7:	48 8d 35 1a 29 00 00 	lea    0x291a(%rip),%rsi        # 4018 <__TMC_END__>
    16fe:	48 29 fe             	sub    %rdi,%rsi
    1701:	48 89 f0             	mov    %rsi,%rax
    1704:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1708:	48 c1 f8 03          	sar    $0x3,%rax
    170c:	48 01 c6             	add    %rax,%rsi
    170f:	48 d1 fe             	sar    %rsi
    1712:	74 14                	je     1728 <register_tm_clones+0x38>
    1714:	48 8b 05 d5 28 00 00 	mov    0x28d5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    171b:	48 85 c0             	test   %rax,%rax
    171e:	74 08                	je     1728 <register_tm_clones+0x38>
    1720:	ff e0                	jmpq   *%rax
    1722:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1728:	c3                   	retq   
    1729:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001730 <__do_global_dtors_aux>:
    1730:	f3 0f 1e fa          	endbr64 
    1734:	80 3d 55 2c 00 00 00 	cmpb   $0x0,0x2c55(%rip)        # 4390 <completed.8060>
    173b:	75 2b                	jne    1768 <__do_global_dtors_aux+0x38>
    173d:	55                   	push   %rbp
    173e:	48 83 3d 8a 28 00 00 	cmpq   $0x0,0x288a(%rip)        # 3fd0 <__cxa_finalize@GLIBC_2.2.5>
    1745:	00 
    1746:	48 89 e5             	mov    %rsp,%rbp
    1749:	74 0c                	je     1757 <__do_global_dtors_aux+0x27>
    174b:	48 8b 3d b6 28 00 00 	mov    0x28b6(%rip),%rdi        # 4008 <__dso_handle>
    1752:	e8 b9 f9 ff ff       	callq  1110 <__cxa_finalize@plt>
    1757:	e8 64 ff ff ff       	callq  16c0 <deregister_tm_clones>
    175c:	c6 05 2d 2c 00 00 01 	movb   $0x1,0x2c2d(%rip)        # 4390 <completed.8060>
    1763:	5d                   	pop    %rbp
    1764:	c3                   	retq   
    1765:	0f 1f 00             	nopl   (%rax)
    1768:	c3                   	retq   
    1769:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001770 <frame_dummy>:
    1770:	f3 0f 1e fa          	endbr64 
    1774:	e9 77 ff ff ff       	jmpq   16f0 <register_tm_clones>
    1779:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001780 <_ZNK9Matrix2x29printmtrxEv>:
    1780:	f3 0f 1e fa          	endbr64 
    1784:	41 55                	push   %r13
    1786:	4c 8d 6f 10          	lea    0x10(%rdi),%r13
    178a:	41 54                	push   %r12
    178c:	4c 8d 25 ad 28 00 00 	lea    0x28ad(%rip),%r12        # 4040 <_ZSt4cout@@GLIBCXX_3.4>
    1793:	55                   	push   %rbp
    1794:	53                   	push   %rbx
    1795:	48 89 fb             	mov    %rdi,%rbx
    1798:	48 83 ec 18          	sub    $0x18,%rsp
    179c:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    17a3:	00 00 
    17a5:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    17aa:	31 c0                	xor    %eax,%eax
    17ac:	48 8d 6c 24 07       	lea    0x7(%rsp),%rbp
    17b1:	4c 89 e7             	mov    %r12,%rdi
    17b4:	66 0f ef c0          	pxor   %xmm0,%xmm0
    17b8:	48 83 c3 08          	add    $0x8,%rbx
    17bc:	f3 0f 5a 43 f8       	cvtss2sd -0x8(%rbx),%xmm0
    17c1:	e8 ea f9 ff ff       	callq  11b0 <_ZNSo9_M_insertIdEERSoT_@plt>
    17c6:	ba 01 00 00 00       	mov    $0x1,%edx
    17cb:	48 89 ee             	mov    %rbp,%rsi
    17ce:	48 89 c7             	mov    %rax,%rdi
    17d1:	c6 44 24 07 20       	movb   $0x20,0x7(%rsp)
    17d6:	e8 95 f9 ff ff       	callq  1170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>
    17db:	4c 89 e7             	mov    %r12,%rdi
    17de:	66 0f ef c0          	pxor   %xmm0,%xmm0
    17e2:	f3 0f 5a 43 fc       	cvtss2sd -0x4(%rbx),%xmm0
    17e7:	e8 c4 f9 ff ff       	callq  11b0 <_ZNSo9_M_insertIdEERSoT_@plt>
    17ec:	ba 01 00 00 00       	mov    $0x1,%edx
    17f1:	48 89 ee             	mov    %rbp,%rsi
    17f4:	48 89 c7             	mov    %rax,%rdi
    17f7:	c6 44 24 07 20       	movb   $0x20,0x7(%rsp)
    17fc:	e8 6f f9 ff ff       	callq  1170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>
    1801:	ba 01 00 00 00       	mov    $0x1,%edx
    1806:	48 89 ee             	mov    %rbp,%rsi
    1809:	4c 89 e7             	mov    %r12,%rdi
    180c:	c6 44 24 07 0a       	movb   $0xa,0x7(%rsp)
    1811:	e8 5a f9 ff ff       	callq  1170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>
    1816:	4c 39 eb             	cmp    %r13,%rbx
    1819:	75 96                	jne    17b1 <_ZNK9Matrix2x29printmtrxEv+0x31>
    181b:	ba 01 00 00 00       	mov    $0x1,%edx
    1820:	48 89 ee             	mov    %rbp,%rsi
    1823:	c6 44 24 07 0a       	movb   $0xa,0x7(%rsp)
    1828:	48 8d 3d 11 28 00 00 	lea    0x2811(%rip),%rdi        # 4040 <_ZSt4cout@@GLIBCXX_3.4>
    182f:	e8 3c f9 ff ff       	callq  1170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>
    1834:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    1839:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1840:	00 00 
    1842:	75 0b                	jne    184f <_ZNK9Matrix2x29printmtrxEv+0xcf>
    1844:	48 83 c4 18          	add    $0x18,%rsp
    1848:	5b                   	pop    %rbx
    1849:	5d                   	pop    %rbp
    184a:	41 5c                	pop    %r12
    184c:	41 5d                	pop    %r13
    184e:	c3                   	retq   
    184f:	e8 0c f9 ff ff       	callq  1160 <__stack_chk_fail@plt>
    1854:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    185b:	00 00 00 00 
    185f:	90                   	nop

0000000000001860 <_ZN9Matrix2x210showResultERKS_>:
    1860:	f3 0f 1e fa          	endbr64 
    1864:	41 55                	push   %r13
    1866:	4c 8d 6f 10          	lea    0x10(%rdi),%r13
    186a:	41 54                	push   %r12
    186c:	4c 8d 25 cd 27 00 00 	lea    0x27cd(%rip),%r12        # 4040 <_ZSt4cout@@GLIBCXX_3.4>
    1873:	55                   	push   %rbp
    1874:	53                   	push   %rbx
    1875:	48 89 fb             	mov    %rdi,%rbx
    1878:	48 83 ec 18          	sub    $0x18,%rsp
    187c:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1883:	00 00 
    1885:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    188a:	31 c0                	xor    %eax,%eax
    188c:	48 8d 6c 24 07       	lea    0x7(%rsp),%rbp
    1891:	4c 89 e7             	mov    %r12,%rdi
    1894:	66 0f ef c0          	pxor   %xmm0,%xmm0
    1898:	48 83 c3 08          	add    $0x8,%rbx
    189c:	f3 0f 5a 43 f8       	cvtss2sd -0x8(%rbx),%xmm0
    18a1:	e8 0a f9 ff ff       	callq  11b0 <_ZNSo9_M_insertIdEERSoT_@plt>
    18a6:	ba 01 00 00 00       	mov    $0x1,%edx
    18ab:	48 89 ee             	mov    %rbp,%rsi
    18ae:	48 89 c7             	mov    %rax,%rdi
    18b1:	c6 44 24 07 20       	movb   $0x20,0x7(%rsp)
    18b6:	e8 b5 f8 ff ff       	callq  1170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>
    18bb:	4c 89 e7             	mov    %r12,%rdi
    18be:	66 0f ef c0          	pxor   %xmm0,%xmm0
    18c2:	f3 0f 5a 43 fc       	cvtss2sd -0x4(%rbx),%xmm0
    18c7:	e8 e4 f8 ff ff       	callq  11b0 <_ZNSo9_M_insertIdEERSoT_@plt>
    18cc:	ba 01 00 00 00       	mov    $0x1,%edx
    18d1:	48 89 ee             	mov    %rbp,%rsi
    18d4:	48 89 c7             	mov    %rax,%rdi
    18d7:	c6 44 24 07 20       	movb   $0x20,0x7(%rsp)
    18dc:	e8 8f f8 ff ff       	callq  1170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>
    18e1:	ba 01 00 00 00       	mov    $0x1,%edx
    18e6:	48 89 ee             	mov    %rbp,%rsi
    18e9:	4c 89 e7             	mov    %r12,%rdi
    18ec:	c6 44 24 07 0a       	movb   $0xa,0x7(%rsp)
    18f1:	e8 7a f8 ff ff       	callq  1170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>
    18f6:	4c 39 eb             	cmp    %r13,%rbx
    18f9:	75 96                	jne    1891 <_ZN9Matrix2x210showResultERKS_+0x31>
    18fb:	ba 01 00 00 00       	mov    $0x1,%edx
    1900:	48 89 ee             	mov    %rbp,%rsi
    1903:	c6 44 24 07 0a       	movb   $0xa,0x7(%rsp)
    1908:	48 8d 3d 31 27 00 00 	lea    0x2731(%rip),%rdi        # 4040 <_ZSt4cout@@GLIBCXX_3.4>
    190f:	e8 5c f8 ff ff       	callq  1170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>
    1914:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    1919:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1920:	00 00 
    1922:	75 0b                	jne    192f <_ZN9Matrix2x210showResultERKS_+0xcf>
    1924:	48 83 c4 18          	add    $0x18,%rsp
    1928:	5b                   	pop    %rbx
    1929:	5d                   	pop    %rbp
    192a:	41 5c                	pop    %r12
    192c:	41 5d                	pop    %r13
    192e:	c3                   	retq   
    192f:	e8 2c f8 ff ff       	callq  1160 <__stack_chk_fail@plt>
    1934:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    193b:	00 00 00 00 
    193f:	90                   	nop

0000000000001940 <_ZN9Matrix2x25inputERS_>:
    1940:	f3 0f 1e fa          	endbr64 
    1944:	53                   	push   %rbx
    1945:	48 89 fe             	mov    %rdi,%rsi
    1948:	48 89 fb             	mov    %rdi,%rbx
    194b:	48 8d 3d 0e 28 00 00 	lea    0x280e(%rip),%rdi        # 4160 <_ZSt3cin@@GLIBCXX_3.4>
    1952:	e8 99 f8 ff ff       	callq  11f0 <_ZNSi10_M_extractIfEERSiRT_@plt>
    1957:	48 8d 73 04          	lea    0x4(%rbx),%rsi
    195b:	48 8d 3d fe 27 00 00 	lea    0x27fe(%rip),%rdi        # 4160 <_ZSt3cin@@GLIBCXX_3.4>
    1962:	e8 89 f8 ff ff       	callq  11f0 <_ZNSi10_M_extractIfEERSiRT_@plt>
    1967:	48 8d 73 08          	lea    0x8(%rbx),%rsi
    196b:	48 8d 3d ee 27 00 00 	lea    0x27ee(%rip),%rdi        # 4160 <_ZSt3cin@@GLIBCXX_3.4>
    1972:	e8 79 f8 ff ff       	callq  11f0 <_ZNSi10_M_extractIfEERSiRT_@plt>
    1977:	48 8d 73 0c          	lea    0xc(%rbx),%rsi
    197b:	48 8d 3d de 27 00 00 	lea    0x27de(%rip),%rdi        # 4160 <_ZSt3cin@@GLIBCXX_3.4>
    1982:	5b                   	pop    %rbx
    1983:	e9 68 f8 ff ff       	jmpq   11f0 <_ZNSi10_M_extractIfEERSiRT_@plt>
    1988:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    198f:	00 

0000000000001990 <_Z6printVI7Vector3ERSt14basic_ofstreamIcSt11char_traitsIcEES5_RKT_>:
    1990:	f3 0f 1e fa          	endbr64 
    1994:	41 54                	push   %r12
    1996:	49 89 fc             	mov    %rdi,%r12
    1999:	55                   	push   %rbp
    199a:	53                   	push   %rbx
    199b:	48 89 f3             	mov    %rsi,%rbx
    199e:	48 83 ec 10          	sub    $0x10,%rsp
    19a2:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    19a9:	00 00 
    19ab:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    19b0:	31 c0                	xor    %eax,%eax
    19b2:	48 8b 07             	mov    (%rdi),%rax
    19b5:	48 8b 40 e8          	mov    -0x18(%rax),%rax
    19b9:	f6 44 07 20 05       	testb  $0x5,0x20(%rdi,%rax,1)
    19be:	0f 85 c4 00 00 00    	jne    1a88 <_Z6printVI7Vector3ERSt14basic_ofstreamIcSt11char_traitsIcEES5_RKT_+0xf8>
    19c4:	8b 05 ca 29 00 00    	mov    0x29ca(%rip),%eax        # 4394 <_ZZ6printVI7Vector3ERSt14basic_ofstreamIcSt11char_traitsIcEES5_RKT_E9num_calls>
    19ca:	4c 89 e7             	mov    %r12,%rdi
    19cd:	8d 70 01             	lea    0x1(%rax),%esi
    19d0:	89 35 be 29 00 00    	mov    %esi,0x29be(%rip)        # 4394 <_ZZ6printVI7Vector3ERSt14basic_ofstreamIcSt11char_traitsIcEES5_RKT_E9num_calls>
    19d6:	e8 e5 f7 ff ff       	callq  11c0 <_ZNSolsEi@plt>
    19db:	ba 02 00 00 00       	mov    $0x2,%edx
    19e0:	48 8d 35 41 06 00 00 	lea    0x641(%rip),%rsi        # 2028 <_IO_stdin_used+0x28>
    19e7:	48 89 c5             	mov    %rax,%rbp
    19ea:	48 89 c7             	mov    %rax,%rdi
    19ed:	e8 7e f7 ff ff       	callq  1170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>
    19f2:	48 89 ef             	mov    %rbp,%rdi
    19f5:	66 0f ef c0          	pxor   %xmm0,%xmm0
    19f9:	f3 0f 5a 03          	cvtss2sd (%rbx),%xmm0
    19fd:	e8 ae f7 ff ff       	callq  11b0 <_ZNSo9_M_insertIdEERSoT_@plt>
    1a02:	ba 02 00 00 00       	mov    $0x2,%edx
    1a07:	48 8d 35 1a 06 00 00 	lea    0x61a(%rip),%rsi        # 2028 <_IO_stdin_used+0x28>
    1a0e:	48 89 c5             	mov    %rax,%rbp
    1a11:	48 89 c7             	mov    %rax,%rdi
    1a14:	e8 57 f7 ff ff       	callq  1170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>
    1a19:	48 89 ef             	mov    %rbp,%rdi
    1a1c:	66 0f ef c0          	pxor   %xmm0,%xmm0
    1a20:	f3 0f 5a 43 04       	cvtss2sd 0x4(%rbx),%xmm0
    1a25:	e8 86 f7 ff ff       	callq  11b0 <_ZNSo9_M_insertIdEERSoT_@plt>
    1a2a:	ba 02 00 00 00       	mov    $0x2,%edx
    1a2f:	48 8d 35 f2 05 00 00 	lea    0x5f2(%rip),%rsi        # 2028 <_IO_stdin_used+0x28>
    1a36:	48 89 c5             	mov    %rax,%rbp
    1a39:	48 89 c7             	mov    %rax,%rdi
    1a3c:	e8 2f f7 ff ff       	callq  1170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>
    1a41:	48 89 ef             	mov    %rbp,%rdi
    1a44:	66 0f ef c0          	pxor   %xmm0,%xmm0
    1a48:	f3 0f 5a 43 08       	cvtss2sd 0x8(%rbx),%xmm0
    1a4d:	e8 5e f7 ff ff       	callq  11b0 <_ZNSo9_M_insertIdEERSoT_@plt>
    1a52:	48 8d 74 24 07       	lea    0x7(%rsp),%rsi
    1a57:	ba 01 00 00 00       	mov    $0x1,%edx
    1a5c:	48 89 c7             	mov    %rax,%rdi
    1a5f:	c6 44 24 07 0a       	movb   $0xa,0x7(%rsp)
    1a64:	e8 07 f7 ff ff       	callq  1170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>
    1a69:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    1a6e:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1a75:	00 00 
    1a77:	75 2c                	jne    1aa5 <_Z6printVI7Vector3ERSt14basic_ofstreamIcSt11char_traitsIcEES5_RKT_+0x115>
    1a79:	48 83 c4 10          	add    $0x10,%rsp
    1a7d:	4c 89 e0             	mov    %r12,%rax
    1a80:	5b                   	pop    %rbx
    1a81:	5d                   	pop    %rbp
    1a82:	41 5c                	pop    %r12
    1a84:	c3                   	retq   
    1a85:	0f 1f 00             	nopl   (%rax)
    1a88:	ba 1f 00 00 00       	mov    $0x1f,%edx
    1a8d:	48 8d 35 74 05 00 00 	lea    0x574(%rip),%rsi        # 2008 <_IO_stdin_used+0x8>
    1a94:	48 8d 3d e5 27 00 00 	lea    0x27e5(%rip),%rdi        # 4280 <_ZSt4cerr@@GLIBCXX_3.4>
    1a9b:	e8 d0 f6 ff ff       	callq  1170 <_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@plt>
    1aa0:	e9 1f ff ff ff       	jmpq   19c4 <_Z6printVI7Vector3ERSt14basic_ofstreamIcSt11char_traitsIcEES5_RKT_+0x34>
    1aa5:	e8 b6 f6 ff ff       	callq  1160 <__stack_chk_fail@plt>
    1aaa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000001ab0 <__libc_csu_init>:
    1ab0:	f3 0f 1e fa          	endbr64 
    1ab4:	41 57                	push   %r15
    1ab6:	4c 8d 3d 53 22 00 00 	lea    0x2253(%rip),%r15        # 3d10 <__frame_dummy_init_array_entry>
    1abd:	41 56                	push   %r14
    1abf:	49 89 d6             	mov    %rdx,%r14
    1ac2:	41 55                	push   %r13
    1ac4:	49 89 f5             	mov    %rsi,%r13
    1ac7:	41 54                	push   %r12
    1ac9:	41 89 fc             	mov    %edi,%r12d
    1acc:	55                   	push   %rbp
    1acd:	48 8d 2d 4c 22 00 00 	lea    0x224c(%rip),%rbp        # 3d20 <__do_global_dtors_aux_fini_array_entry>
    1ad4:	53                   	push   %rbx
    1ad5:	4c 29 fd             	sub    %r15,%rbp
    1ad8:	48 83 ec 08          	sub    $0x8,%rsp
    1adc:	e8 1f f5 ff ff       	callq  1000 <_init>
    1ae1:	48 c1 fd 03          	sar    $0x3,%rbp
    1ae5:	74 1f                	je     1b06 <__libc_csu_init+0x56>
    1ae7:	31 db                	xor    %ebx,%ebx
    1ae9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1af0:	4c 89 f2             	mov    %r14,%rdx
    1af3:	4c 89 ee             	mov    %r13,%rsi
    1af6:	44 89 e7             	mov    %r12d,%edi
    1af9:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    1afd:	48 83 c3 01          	add    $0x1,%rbx
    1b01:	48 39 dd             	cmp    %rbx,%rbp
    1b04:	75 ea                	jne    1af0 <__libc_csu_init+0x40>
    1b06:	48 83 c4 08          	add    $0x8,%rsp
    1b0a:	5b                   	pop    %rbx
    1b0b:	5d                   	pop    %rbp
    1b0c:	41 5c                	pop    %r12
    1b0e:	41 5d                	pop    %r13
    1b10:	41 5e                	pop    %r14
    1b12:	41 5f                	pop    %r15
    1b14:	c3                   	retq   
    1b15:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    1b1c:	00 00 00 00 

0000000000001b20 <__libc_csu_fini>:
    1b20:	f3 0f 1e fa          	endbr64 
    1b24:	c3                   	retq   

Disassembly of section .fini:

0000000000001b28 <_fini>:
    1b28:	f3 0f 1e fa          	endbr64 
    1b2c:	48 83 ec 08          	sub    $0x8,%rsp
    1b30:	48 83 c4 08          	add    $0x8,%rsp
    1b34:	c3                   	retq   
