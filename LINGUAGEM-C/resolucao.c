/*#include <stdio.h>

int main()
{
    int b, a, d, p, q, c, e, f, g;
    float x, z, r, t, s, v;

    float ra, rb, rc, rd, re, rf, rg, rh, ri, rj, rk, rl, rm, rn, ro, rp, rq, rr; 

    x = 6.0; b = 2; z = 4.0; a = 8; r = 7.5; t = 7.7; d = 12; p = 4;
    q = 3; c = 10; s = 2.5;e = 2; f = 7; v = 3.5; g = 0;

    ra = x + b - z * a ;
    rb = d / b ;
    rc = d % b;
    rd = b / d ;
    re = b % d ;
    rf = ((z / a) + r * a) - d;
    rg = 100 * (q / p) + c ;
    rh = p * (c % q) -q/2 ;
    ri = e<5;
    rj = (f == (e*v)) && g || 1 ;
    rk = !(e<5) ;
    rl = (e*v/f) > (e*f*v);
    rm = e<5 || 15 && 0 ;
    rn = 2 == e > 0 ;
    ro = !1 == 0;
    rp = 2<f<5 ;
    rq = (2<f)||(f<5); 
    rr = (2<f)&&(f<5);

    printf("aResultado = %.0f\n",ra);
    printf("bResultado = %f\n",rb);
    printf("cResultado = %f\n", rc);
    printf("dResultado = %f\n", rd);
    printf("eResultado = %f\n", re);
    printf("fResultado = %f\n", rf);
    printf("gResultado = %f\n", rg);
    printf("hResultado = %f\n", rh);
    printf("iResultado = %f\n", ri);
    printf("jResultado = %f\n", rj);
    printf("kResultado = %f\n", rk);
    printf("lResultado = %f\n", rl);
    printf("mResultado = %f\n", rm);
    printf("nResultado = %f\n", rn);
    printf("oResultado = %f\n", ro);
    printf("pResultado = %f\n", rp);
    printf("qResultado = %f\n", rq);
    printf("rResultado = %f\n", rr);

    return 0; 
}*/

#include <stdio.h>

int main ()
{
    float grausF, celcius; 

    printf ("Digite uma temperatura em Faharnheit (T-F): ");
    scanf ("%f",&grausF); 

    celcius = (float)5/9*(grausF - 32); 

    printf ("O valor de (T-F) em Celcius E: %.2f",celcius); 
    return 0; 
}