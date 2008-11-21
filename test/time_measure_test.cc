/* -*- mode: C++; indent-tabs-mode: nil; -*-
 *
 * This file is a part of LEMON, a generic C++ optimization library.
 *
 * Copyright (C) 2003-2008
 * Egervary Jeno Kombinatorikus Optimalizalasi Kutatocsoport
 * (Egervary Research Group on Combinatorial Optimization, EGRES).
 *
 * Permission to use, modify and distribute this software is granted
 * provided that this copyright notice appears in all copies. For
 * precise terms see the accompanying LICENSE file.
 *
 * This software is provided "AS IS" with no warranty of any kind,
 * express or implied, and with no claim as to its suitability for any
 * purpose.
 *
 */

#include <lemon/time_measure.h>

using namespace lemon;

void f()
{
  double d=0;
  for(int i=0;i<1000;i++)
    d+=0.1;
}

void g()
{
  static Timer T;

  for(int i=0;i<1000;i++)
    TimeStamp x(T);
}

int main()
{
  Timer T;
  unsigned int n;
  for(n=0;T.realTime()<1.0;n++) ;
  std::cout << T << " (" << n << " time queries)\n";
  T.restart();
  while(T.realTime()<2.0) ;
  std::cout << T << '\n';
  TimeStamp full;
  TimeStamp t;
  t=runningTimeTest(f,1,&n,&full);
  std::cout << t << " (" << n << " tests)\n";
  std::cout << "Total: " << full << "\n";

  t=runningTimeTest(g,1,&n,&full);
  std::cout << t << " (" << n << " tests)\n";
  std::cout << "Total: " << full << "\n";

  return 0;
}
