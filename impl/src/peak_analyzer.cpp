#include "peak_analyzer.h"
#include "exceptions.h"
#include <iostream>

namespace peak {

PeakAnalyzer::PeakAnalyzer() : event_generator() {}

void PeakAnalyzer::analyze_events(const int no_of_events) {
  event_generator.generate_events(no_of_events);
  if (event_generator.no_of_generated_events() == 0) {
    throw NoGeneratedEventsException();
  } else {
    std::cout << "Right edge event is: " << right_edge_event() << std::endl;
    std::cout << "Left edge event is: " << left_edge_event() << std::endl;
    std::cout << "Event with first time stamp is: " << first_time_stamp()
              << std::endl;
    std::cout << "Event with last time stamp is: " << last_time_stamp()
              << std::endl;
    std::cout << "In one sigma, number of generated events is: "
              << one_sigma_from_mean() << "%" << std::endl;
    std::cout << "In two sigma, number of generated events is: "
              << two_sigma_from_mean() << "%" << std::endl;
    std::cout << "In three sigma, number of generated events is: "
              << three_sigma_from_mean() << "%" << std::endl;
  }
}

void PeakAnalyzer::print_events() const { event_generator.print_events(); }

float PeakAnalyzer::right_edge_event() const {
  return event_generator.right_edge_event();
}

float PeakAnalyzer::left_edge_event() const {
  return event_generator.left_edge_event();
}

long PeakAnalyzer::first_time_stamp() const {
  return event_generator.first_event();
}

long PeakAnalyzer::last_time_stamp() const {
  return event_generator.last_event();
}

float PeakAnalyzer::one_sigma_from_mean() const {
  return event_generator.no_of_events_in_one_sigma();
}

float PeakAnalyzer::two_sigma_from_mean() const {
  return event_generator.no_of_events_in_two_sigma();
}

float PeakAnalyzer::three_sigma_from_mean() const {
  return event_generator.no_of_events_in_three_sigma();
}

} // namespace peak
