#include "smart_calc.h"

double GetN(char **src, int *err) {
  double val = 0;
  double partial = 0;
  double sign = GetSign(src, err);
  char s = **src;

  while ('0' <= **src && **src <= '9') {
    val *= 10;
    val += (**src - '0');
    (*src)++;
  }
  if (s == **src) *err = 1;
  if (**src == '.') {
    (*src)++;
    int i = 1;
    s = **src;
    while ('0' <= **src && **src <= '9') {
      partial += (**src - '0') / powl(10, i);
      (*src)++;
      i++;
    }
    val += partial;
    if (s == **src) *err = 1;
  }
  val *= sign;
  return val;
}
double GetSign(char **src, int *err) {
  double res = 1L;
  if (**src == '-') {
    res = -1L;
    (*src)++;
  } else if (**src == '+') {
    (*src)++;
  }
  return (res);
}
int CheckSin(char **src, int *err) {
  int res = 0;
  if (strlen(*src) > 4 && !strncmp(*src, "sin(\0", 4)) {
    res = 1;
    (*src)+=4;
  }
  return res;
}
int CheckCos(char **src, int *err) {
  int res = 0;
  if (strlen(*src) > 4 && !strncmp(*src, "cos(\0", 4)) {
    res = 1;
    for (int i = 0; i < 4; i++) {
      (*src)++;
    }
  }
  return res;
}
int CheckTan(char **src, int *err) {
  int res = 0;
  if (strlen(*src) > 4 && !strncmp(*src, "tan(\0", 4)) {
    res = 1;
    for (int i = 0; i < 4; i++) {
      (*src)++;
    }
  }
  return res;
}
int CheckAcos(char **src, int *err) {
  int res = 0;
  if (strlen(*src) > 5 && !strncmp(*src, "acos(\0", 5)) {
    res = 1;
    for (int i = 0; i < 5; i++) {
      (*src)++;
    }
  }
  return res;
}
int CheckAsin(char **src, int *err) {
  int res = 0;
  if (strlen(*src) > 5 && !strncmp(*src, "asin(\0", 5)) {
    res = 1;
    for (int i = 0; i < 5; i++) {
      (*src)++;
    }
  }
  return res;
}
int CheckAtan(char **src, int *err) {
  int res = 0;
  if (strlen(*src) > 5 && !strncmp(*src, "atan(\0", 5)) {
    res = 1;
    for (int i = 0; i < 5; i++) {
      (*src)++;
    }
  }
  return res;
}
int CheckSqrt(char **src, int *err) {
  int res = 0;
  if (strlen(*src) > 5 && !strncmp(*src, "sqrt(\0", 5)) {
    res = 1;
    for (int i = 0; i < 5; i++) {
      (*src)++;
    }
  }
  return res;
}
int CheckLog(char **src, int *err) {
  int res = 0;
  if (strlen(*src) > 4 && !strncmp(*src, "log(\0", 4)) {
    res = 1;
    for (int i = 0; i < 4; i++) {
      (*src)++;
    }
  }
  return res;
}
int CheckLog10(char **src, int *err) {
  int res = 0;
  if (strlen(*src) > 6 && !strncmp(*src, "log10(\0", 6)) {
    res = 1;
    for (int i = 0; i < 6; i++) {
      (*src)++;
    }
  }
  return res;
}
int CheckPi(char **src, int *err) {
  int res = 0;
  if (strlen(*src) > 2 && !strncmp(*src, "pi\0", 2)) {
    res = 1;
    for (int i = 0; i < 2; i++) {
      (*src)++;
    }
  }
  return res;
}
int CheckExp(char **src, int *err) {
  int res = 0;
  if (strlen(*src) > 4 && !strncmp(*src, "exp(\0", 4)) {
    res = 1;
    for (int i = 0; i < 4; i++) {
      (*src)++;
    }
  }
  return res;
}
int CheckX(char **src, int *err) {
  int res = 0;
  if (strlen(*src) > 1 && !strncmp(*src, "x\0", 1)) {
    res = 1;
    (*src)++;
  }
  return res;
}
double GetP(char **src, int *err, double x) {
  double val = 0;
  double sign = GetSign(src, err);

  if (**src == '(') {
    (*src)++;
    val = GetE(src, err, x);
    if (**src != ')')
      *err = 1;
    else {
      (*src)++;
    }
  } else if (CheckSin(src, err)) {
    val = GetE(src, err, x);
    val = sin(val);
    if (**src != ')')
      *err = 1;
    else
      (*src)++;
  } else if (CheckCos(src, err)) {
    val = GetE(src, err, x);
    val = cos(val);
    if (**src != ')')
      *err = 1;
    else
      (*src)++;
  } else if (CheckTan(src, err)) {
    val = GetE(src, err, x);
    val = tan(val);
    if (**src != ')')
      *err = 1;
    else
      (*src)++;
  } else if (CheckAcos(src, err)) {
    val = GetE(src, err, x);
    val = acos(val);
    if (**src != ')')
      *err = 1;
    else
      (*src)++;
  } else if (CheckAsin(src, err)) {
    val = GetE(src, err, x);
    val = asin(val);
    if (**src != ')')
      *err = 1;
    else
      (*src)++;
  } else if (CheckAtan(src, err)) {
    val = GetE(src, err, x);
    val = atan(val);
    if (**src != ')')
      *err = 1;
    else
      (*src)++;
  } else if (CheckSqrt(src, err)) {
    val = GetE(src, err, x);
    val = sqrt(val);
    if (**src != ')')
      *err = 1;
    else
      (*src)++;
  } else if (CheckLog(src, err)) {
    val = GetE(src, err, x);
    val = log(val);
    if (**src != ')')
      *err = 1;
    else
      (*src)++;
  } else if (CheckLog10(src, err)) {
    val = GetE(src, err, x);
    val = log10(val);
    if (**src != ')')
      *err = 1;
    else
      (*src)++;
  } else if (CheckPi(src, err)) {
    val = M_PI;
  } else if (CheckExp(src, err)) {
    val = GetE(src, err, x);
    val = expl(val);
    if (**src != ')')
      *err = 1;
    else
      (*src)++;
  } else if (CheckX(src, err)) {
    val = x;
  } else {
    val = GetN(src, err);
  }
  return val * sign;
}
double GetR(char **src, int *err, double x) {
  double val = 0;
  val = GetP(src, err, x);
  while (**src == '^') {
    (*src)++;
    double power = GetP(src, err, x);
    val = powl(val, power);
  }
  return val;
}
double GetT(char **src, int *err, double x) {
  double val = 0;
  char sign = 0;
  val = GetR(src, err, x);
  while (**src == '*' || **src == '/' || **src == '%') {
    sign = **src;
    (*src)++;
    double addition = GetR(src, err, x);
    if (sign == '*') val *= addition;
    if (sign == '/') val /= addition;
    if (sign == '%') val = fmodl(val, addition);
  }
  return val;
}
double GetE(char **src, int *err, double x) {
  double val = 0;
  char sign = 0;
  double addition = 0;
  val = GetT(src, err, x);
  while (**src == '+' || **src == '-') {
    sign = **src;
    (*src)++;
    double addition = GetT(src, err, x);
    if (sign == '+') val += addition;
    if (sign == '-') val -= addition;
  }
  return val;
}
double GetG(char **src, int *err, double x) {
  double val = 0;
  double sign = 1L;
  val = GetE(src, err, x);
  val *= sign;
  if (**src != '=') *err = 1;
  return val;
}
double calculate(char *src, int *err, double x) {
  double res = GetG(&src, err, x);
  if (isnan(res)) *err = 1;
  return res;
}
