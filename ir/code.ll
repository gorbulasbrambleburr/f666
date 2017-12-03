target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-samsung-linux"

define i32 @A() #0 {
  %1 = alloca i32, align 4				;  var A
  %2 = alloca i32, align 4				;  var I
  %3 = alloca double, align 8				;  var J
  store i32 10, i32* %2, align 4
  store double 2.000000, double* %3, align 8
  ret i32 %1
}

