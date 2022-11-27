#include "event_generator.h"
#include <boost/bimap/support/lambda.hpp>
#include <boost/foreach.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/variate_generator.hpp>
#include <chrono>
#include <iostream>

namespace peak {

void EventGenerator::generate_events(const int no_of_events) {
  event_number = no_of_events;
  boost::mt19937 igen;
  boost::variate_generator<boost::mt19937, boost::normal_distribution<>> gen(
      igen, boost::normal_distribution<>(mean, variance));

  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  auto millis =
      std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

  for (size_t i = 0; i < no_of_events; ++i) {
    events.insert(time_stamp((float)gen(), (long)(millis + i)));
  }
}

void EventGenerator::print_events() const {
  for (Events::const_iterator iter = events.begin(), iend = events.end();
       iter != iend; ++iter) {
    std::cout << iter->left << " <--> " << iter->right << std::endl;
  }
}

float EventGenerator::right_edge_event() const {
  Events::left_const_iterator start = events.left.begin();
  Events::left_const_iterator stop = events.left.end();
  auto max = std::max_element(start, stop);
  return max->first;
}

float EventGenerator::left_edge_event() const {
  Events::left_const_iterator start = events.left.begin();
  Events::left_const_iterator stop = events.left.end();
  auto min = std::min_element(start, stop);
  return min->first;
}

long EventGenerator::first_event() const {
  Events::right_const_iterator start = events.right.begin();
  Events::right_const_iterator stop = events.right.end();
  auto min = std::min_element(start, stop);
  return min->first;
}

long EventGenerator::last_event() const {
  Events::right_const_iterator start = events.right.begin();
  Events::right_const_iterator stop = events.right.end();
  auto max = std::max_element(start, stop);
  return max->first;
}

float EventGenerator::no_of_events_in_one_sigma() const {
  int no = 0;
  BOOST_FOREACH (Events::left_const_reference p,
                 (events.left.range((mean - variance) < boost::bimaps::_key,
                                    boost::bimaps::_key < (mean + variance)))) {
    ++no;
  }
  return (float)no / event_number * 100.0;
}

float EventGenerator::no_of_events_in_two_sigma() const {
  int no = 0;
  BOOST_FOREACH (
      Events::left_const_reference p,
      (events.left.range((mean - 2 * variance) < boost::bimaps::_key,
                         boost::bimaps::_key < (mean + 2 * variance)))) {
    ++no;
  }
  return (float)no / event_number * 100.0;
}

float EventGenerator::no_of_events_in_three_sigma() const {
  int no = 0;
  BOOST_FOREACH (
      Events::left_const_reference p,
      (events.left.range((mean - 3 * variance) < boost::bimaps::_key,
                         boost::bimaps::_key < (mean + 3 * variance)))) {
    ++no;
  }
  return (float)no / event_number * 100.0;
}

} // namespace peak
