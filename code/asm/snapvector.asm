; 

; MASM version of snapvector conversion function using SSE or FPU
; assume __cdecl calling convention is being used for x86, __fastcall for x64
;
; function prototype:
; void qsnapvector(vec3_t vec)

IFNDEF idx64
.686p
.xmm
.model flat, c
ENDIF

.data

  ALIGN 16
  ssemask DWORD 0FFFFFFFFh, 0FFFFFFFFh, 0FFFFFFFFh, 00000000h
  ssecw DWORD 00001F80h

.code

IFDEF idx64
; qsnapvector using SSE

  qsnapvectorsse PROC
	movaps xmm1, ssemask		; initialize the mask register
	movups xmm0, [rcx]			; here is stored our vector. Read 4 values in one go
	movaps xmm2, xmm0			; keep a copy of the original data
	andps xmm0, xmm1			; set the fourth value to zero in xmm0
	andnps xmm1, xmm2			; copy fourth value to xmm1 and set rest to zero
	cvtps2dq xmm0, xmm0			; convert 4 single fp to int
	cvtdq2ps xmm0, xmm0			; convert 4 int to single fp
	orps xmm0, xmm1				; combine all 4 values again
	movups [rcx], xmm0			; write 3 rounded and 1 unchanged values back to memory
	ret
  qsnapvectorsse ENDP

ELSE

  qsnapvectorsse PROC
	mov eax, dword ptr 4[esp]		; store address of vector in eax
	movaps xmm1, ssemask			; initialize the mask register for maskmovdqu
	movups xmm0, [eax]			; here is stored our vector. Read 4 values in one go
	movaps xmm2, xmm0			; keep a copy of the original data
	andps xmm0, xmm1			; set the fourth value to zero in xmm0
	andnps xmm1, xmm2			; copy fourth value to xmm1 and set rest to zero
	cvtps2dq xmm0, xmm0			; convert 4 single fp to int
	cvtdq2ps xmm0, xmm0			; convert 4 int to single fp
	orps xmm0, xmm1				; combine all 4 values again
	movups [eax], xmm0			; write 3 rounded and 1 unchanged values back to memory
	ret
  qsnapvectorsse ENDP

  qroundx87 macro src
	fld dword ptr src
	fistp dword ptr src
	fild dword ptr src
	fstp dword ptr src
  endm    

  qsnapvectorx87 PROC
	mov eax, dword ptr 4[esp]
	qroundx87 [eax]
	qroundx87 4[eax]
	qroundx87 8[eax]
	ret
  qsnapvectorx87 ENDP

ENDIF

end
