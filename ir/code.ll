target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-samsung-linux"

define i32 @A() #0 {
  %1 = alloca i32, align 4				;  var A
  %2 = alloca i32, align 4				;  var I
  %3 = alloca i32, align 4				;  var J
  ret i32 %1
}

