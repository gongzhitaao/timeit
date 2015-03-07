#if __cplusplus <= 199711L

// C++0x

#include <ctime>

class Timer
{
 public:
  Timer() { clock_gettime(CLOCK_REALTIME, &beg_); }

  double elapsed() {
    clock_gettime(CLOCK_REALTIME, &end_);
    return end_.tv_sec - beg_.tv_sec +
        (end_.tv_nsec - beg_.tv_nsec) / 1000000000.;
  }

  void reset() { clock_gettime(CLOCK_REALTIME, &beg_); }

 private:
  timespec beg_, end_;
};

#else

// C++11

#include <chrono>

class Timer
{
 public:
  Timer() : beg_(clock_::now()) {}
  void reset() { beg_ = clock_::now(); }
  double elapsed() const {
    return std::chrono::duration_cast<second_>
        (clock_::now() - beg_).count(); }

 private:
  typedef std::chrono::high_resolution_clock clock_;
  typedef std::chrono::duration<double, std::ratio<1> > second_;
  std::chrono::time_point<clock_> beg_;
};

#endif
