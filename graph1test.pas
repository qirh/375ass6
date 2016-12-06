program graph1(output);
label 1492, 1776;
const d = 0.0625; {1/16, 16 lines for interval [x,x+1]}
      s = 32; {32 character widths for interval [y,y+1]}
      h = 34; {character position of x-axis}
      c = 6.28318; {2*pi}  lim = 32;
var u, v, x, y, z : real; i, j, n, counter : integer;
begin
	x := d * i;
	y := i * d;
	z := i;	{ real ASSIGNOP integer }
	counter := 0;
	j := d;	{ integer ASSIGNOP real }
	v := exp(-x) * sin(c * x);
	u := round(s * y) + h;
   for i := lim downto 0 do
      begin
      	x := d*i; y := exp(-x)*sin(c*x);
      	n := round(s*y) + h;
      	repeat write(' ');  n := n-1
      	until n=0;
      	writeln('*')
      end;
    j := 0;
    while j < 10 do
    	begin
			writeln('F');
      j := j + 1
    	end;
1776:
	counter := counter + 1;
1492:
	writeln('A');
    if counter < 3 then goto 1776 else goto 1492
end.{  }
{
	repeat write(' ');  n := n-1
    until n=0;

	for i := s downto 1 do 
		writeln('*')

   (progn (label 0)
          (funcall write ' ')
          (:= n (- n 1))
          (if (= n 0)
              (progn)
              (goto 0)))

   for i := 0 to lim do
      begin x := d*i; y := exp(-x)*sin(c*x);
      n := round(s*y) + h;
      repeat write(' ');  n := n-1
      until n=0;
      writeln('*')
   end

}

{ EXPECTED OUTPUT:

program graph1(output);
const d = 0.0625;
      s = 32;
      h = 34;
      c = 6.28318;	lim = 32;
var x,y : real;  i,n : integer;
begin
   for i := 0 to lim do
      begin x := d*i; y := exp(-x)*sin(c*x);
      n := round(s*y) + h;
      repeat write(' ');  n := n-1
      until n=0;
      writeln('*')
   end
end.

(program graph1
         (progn output)
         (progn (:= i 0)
                (label 1)
                (if (<= i 32)
                    (progn (:= x (* 6.250000e-02
                                    (float i)))
                           (:= y (* (funcall exp (- x))
                                    (funcall sin (* 6.283180e+00 x))))
                           (:= n (fix (+ (funcall round
                                                  (* 3.200000e+01 y))
                                         3.400000e+01)))
                           (progn (label 0)
                                  (funcall write ' ')
                                  (:= n (- n 1))
                                  (if (= n 0)
                                      (progn)
                                      (goto 0)))
                                  (funcall writeln '*')
                                  (:= i (+ i 1))
                                  (goto 1)))))
}
