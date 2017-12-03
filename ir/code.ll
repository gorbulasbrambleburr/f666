target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-samsung-linux"

define i32 @A() #0 {
  %1 = alloca i32, align 4				;  var A
  %2 = alloca i32, align 4				;  var I
  %3 = alloca i32, align 4				;  var J
  store i32 5, i32* %2, align 4
  %4 = load i32, i32* %2, align 4		;  var I
  %5 = add i32 3, %4
  %6 = mul i32 %5, 2
  %7 = add i32 %6, 1
  store i32 %7, i32* %3, align 4
  ret i32 %1
}

