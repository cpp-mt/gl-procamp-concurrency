#pragma once

const int Philosophers_No = 5;

// gather statistics of each philosopher statuses
 struct dining_stat {
   size_t eat_no;
   size_t think_no;
   dining_stat() : eat_no(0), think_no(0) {};
 };


extern dining_stat summary[Philosophers_No];

extern std::atomic<bool> done;

void philosopher(int idx);

