#include "analyzer.h"
#include "event_generator.h"
#include "peak_analyzer.h"

int main() {
  peak::Analyzer *analyzer = new peak::PeakAnalyzer();
  analyzer->analyze_events(1000);
  //  analyzer->print_events();
  delete analyzer;
  return 0;
}
