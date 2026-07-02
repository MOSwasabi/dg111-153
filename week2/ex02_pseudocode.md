โจทย์ A

BEGIN [ตรวจสอบเกรด]
 INPUT [score]
      IF {score >= 80} THEN
         output [เกรด = A]

    Else IF {score >= 70} THEN
         output [เกรด = B]

    Else IF {score >= 60} THEN
          output [เกรด = C]

    Else  IF {score >= 50} THEN
          output [เกรด = D]

    Else {score <= 50}THEN

    output [เกรด = F]

    END IF

    output  เกรด

END

โจทย์ B

BEGIN [หาค่าสูงสุดจาก 2 ตัวเลข]

    INPUT[ a & b]

    IF a > b THAN

    output [/เเสดง a/]

   Else a < b THAN

    output[/เเสดง b/]

    END IF

    output [ตัวเลข]

END

โจทย์ C 

BEGIN [นับจาก 1 ถึง n]

    INPUT[ i = 1]

  if  i <= N THAN

   output [/พิมพ์ i/]

   output i = i + 1

   else End
