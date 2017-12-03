target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-samsung-linux"

define i32 @X() #0 {
  %1 = alloca i32, align 4				;  var X
  %2 = alloca i32, align 4				;  var I
  store i32 0, i32* %2, align 4
  br label %3

; <label>:3:
  %7 = load i32, i32* %2, align 4		;  var I
  %8 = icmp sle i32 %7, 10
  br i1 %8, label %4, label %6

; <label>:4:
  %9 = load i32, i32* %2, align 4		;  var I
  %10 = mul i32 %9, 2
  store i32 %10, i32* %1, align 4
  br label %5

; <label>:5:
  %11 = load i32, i32* %2, align 4		;  var I
  %12 = add i32 %11, 2
  store i32 %12, i32* %2, align 4
  br label %3

; <label>:6:
  ret i32 %1
}

