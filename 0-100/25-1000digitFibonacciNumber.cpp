/*
nth fibonacci number is round(phi**n / sqrt(5))
hence:
    round(phi**n / sqrt(5)) > 10**999
    
    log(phi**n / sqrt(5)) > 999
    log(phi**n) - log(sqrt(5)) > 999

    n*log(phi) > 999 + log(sqrt(5))

    n > (999 + log(sqrt(5)))/log(phi)

    n > 4781.85927075

    n = 4782 (for first integer value)
*/
