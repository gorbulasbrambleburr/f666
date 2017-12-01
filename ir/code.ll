target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-samsung-linux"

define i32 @B(i32, i32) #0 {
  %3 = alloca i32, align 4				;  var A
  store i32 %0, i32* %3, align 4
  %4 = alloca i32, align 4				;  var B
  %5 = alloca i32, align 4				;  var C
  store i32 %1, i32* %5, align 4
  %6 = alloca i32, align 4				;  var D
  %7 = load i32, i32* %3, align 4		;  var A
  %8 = load i32, i32* %5, align 4		;  var C
  %9 = mul i32 %8, 2
  %10 = add i32 %7, %9
  store i32 %10, i32* %4, align 4
  %11 = load i32, i32* %4, align 4		;  var B
  %12 = load i32, i32* %3, align 4		;  var A
  %13 = icmp eq i32 %11, %12
  br i1 %13, label %14, label %15

; <label>:14:
  %16 = load i32, i32* %3, align 4		;  var A
  %17 = load i32, i32* %5, align 4		;  var C
  %18 = sdiv i32 %16, %17
  store i32 %18, i32* %6, align 4
  br label %15

; <label>:15:
  ret i32 %4
}

define void @DO_LOOP(i32) #0 {
  %2 = alloca i32, align 4				;  var X
  store i32 %0, i32* %2, align 4
  %3 = alloca i32, align 4				;  var I
  %4 = alloca i32, align 4				;  var J
  store i32 1, i32* %3, align 4
  br label %5

; <label>:5:
  %9 = load i32, i32* %3, align 4		;  var I
  %10 = icmp sle i32 %9, 10
  br i1 %10, label %6, label %8

; <label>:6:
  %11 = call i32 @B(i32 %3, i32 %2)
  store i32 %11, i32* %4, align 4
  br label %7

; <label>:7:
  %12 = load i32, i32* %3, align 4		;  var I
  %13 = add i32 %12, 2
  store i32 %13, i32* %3, align 4
  br label %5

; <label>:8:
  ret void
}

define void @C(i32) #0 {
  %2 = alloca i32, align 4				;  var X
  store i32 %0, i32* %2, align 4
  %3 = alloca i32, align 4				;  var C
  store i32 5, i32* %3, align 4
  %4 = load i32, i32* %2, align 4		;  var X
  %5 = load i32, i32* %3, align 4		;  var C
  %6 = icmp sgt i32 %4, %5
  br i1 %6, label %7, label %8

; <label>:7:
  %10 = load i32, i32* %2, align 4		;  var X
  %11 = add i32 %10, 1
  store i32 %11, i32* %3, align 4
  br label %9

; <label>:8:
  %12 = load i32, i32* %2, align 4		;  var X
  %13 = sub i32 %12, 1
  store i32 %13, i32* %3, align 4
  br label %9

; <label>:9:
  ret void
}

define @A() #1 {
  %1 = alloca double, align 8				;  var X
  %2 = alloca double, align 8				;  var Y
  %4 = alloca i32, align 4				;  var I
  call void @C(i32 %4)
  store double 10.000000, double* %1, align 8
  %5 = load double, double* %1, align 8		;  var X
  %6 = load double, double* %1, align 8		;  var X
  %7 = mul i32 %5, %6
  %8 = fsub double %7, 3.000000
  store double %8, double* %2, align 8
}

