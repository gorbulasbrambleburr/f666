target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-samsung-linux"

define i32 @MAIOR(i32, i32) #0 {
  %3 = alloca i32, align 4				;  var MAIOR
  %4 = alloca i32, align 4				;  var X
  store i32 %0, i32* %4, align 4
  %5 = alloca i32, align 4				;  var Y
  store i32 %1, i32* %5, align 4
  %6 = load i32, i32* %4, align 4		;  var X
  %7 = load i32, i32* %5, align 4		;  var Y
  %8 = icmp sge i32 %6, %7
  br i1 %8, label %9, label %10

; <label>:9:
  %12 = load i32, i32* %4, align 4		;  var X
  store i32 %12, i32* %3, align 4
  br label %11

; <label>:10:
  %13 = load i32, i32* %5, align 4		;  var Y
  store i32 %13, i32* %3, align 4
  br label %11

; <label>:11:
  ret i32 %3
}

