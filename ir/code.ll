target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-samsung-linux"

define i32 @SUM(i32, i32) #0 {
  %3 = alloca i32, align 4				;  var SUM
  %4 = alloca i32, align 4				;  var X
  store i32 %0, i32* %4, align 4
  %5 = alloca i32, align 4				;  var Y
  store i32 %1, i32* %5, align 4
  %6 = load i32, i32* %4, align 4		;  var X
  %7 = load i32, i32* %5, align 4		;  var Y
  %8 = add i32 %6, %7
  store i32 %8, i32* %3, align 4
  ret i32 %3
}

define @MAIN() #1 {
  %1 = alloca i32, align 4				;  var I
  %2 = alloca i32, align 4				;  var J
  %3 = alloca i32, align 4				;  var K
  store i32 5, i32* %1, align 4
  store i32 2, i32* %2, align 4
  %4 = call i32 @SUM(i32 %1, i32 %3)
  store i32 %4, i32* %3, align 4
}

