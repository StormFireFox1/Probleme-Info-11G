/*
 * Jap2
 * Aceasta problema foloseste Teorema lui Lucas cu inversul modular.
 * In mod principal, inversul modular se deduce din mica teorema a lui Fermat:
 *
 *                     a^(p-1) congruent 1 (mod p) p prim
 *                     a^-1 * a congruent a * a^-1 congruent 1 (mod p)
 *
 *                     Invers modular = a^(p-2)
 *
 * Factorialele se calculeaza banal:
 *                     fact(n) = fact(n - 1) * n (mod p)
 *
 * Teorema lui Lucas:
 *
 * C(N luate cate M) = Produs de C(nk luate cate mk) (mod MOD)
 *
 * N = nk*MOD^(k-1) + n(k-1)*MOD^(k-2) + ... + n0
 * M = mk*MOD^(k-1) + m(k-1)*MOD^(k-2) + ... + n0
 *
 * 
 *
 */

