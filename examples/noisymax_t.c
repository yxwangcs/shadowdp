extern void __VERIFIER_error() __attribute__ ((__noreturn__));
extern int __VERIFIER_nondet_float(void);
extern void __VERIFIER_assume(int);
extern int __VERIFIER_nondet_int();
extern void __assert_fail();
#define __VERIFIER_assert(cond) { if(!(cond)) { __assert_fail(); } }

#define abs(x) ((x)<0 ? -(x) : (x))

typedef enum { false = 0, true = 1 } bool;

#define SIZE 4

int noisymax (float epsilon, float q[], float dq[]) {

  int i = 0;
  float bq = 0, s_bq = 0, dis_bq = 0, v_epsilon = 0;
  float dis_s_bq = s_bq - bq;

  while(i < SIZE)
  {
    float eta = __VERIFIER_nondet_float();
    float s_eta = eta; // maybe define dq[i] in latex
    //v_epsilon = (q[i] + eta > bq || i = 0) ? (abs(1 - dq[i]) * (epsilon / 2.0)) : v_epsilon;
    v_epsilon = (q[i] + eta > bq || i = 0) ? (epsilon / 2.0) : v_epsilon;

    if(q[i] + eta > bq || i == 0)
    {
      __VERIFIER_assert(q[i] + eta + 1 > bq + dis_s_bq || i == 0);
      int max = i;
      bq = q[i] + eta;
      dis_bq = 1;
    }
    else
    {
      __VERIFIER_assert(q[i] + dq[i] + eta <= bq + dis_bq);
    }
    // shadow execution
    if(q[i] + dq[i] + s_eta > s_bq || i == 0)
    {
      int s_max = i;
      s_bq = q[i] + dq[i] + s_eta;
      dis_s_bq = s_bq - bq;
    }
    i = i + 1;
  }
    __VERIFIER_assert(v_epsilon < epsilon);
}

int main() {
  float a[SIZE];
  float da[SIZE];

  unsigned int i;

  for(i = 0; i < SIZE; i++){
    a[i] = __VERIFIER_nondet_float();
  }

  for(i = 0; i < SIZE; i++){
    da[i] = __VERIFIER_nondet_float();
    __VERIFIER_assume(da[i] >= -1 && da[i] <= 1);
  }

  float epsilon = __VERIFIER_nondet_float();
  __VERIFIER_assume(epsilon > 0);

  return noisymax(epsilon, a, da);
}