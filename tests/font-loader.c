#include "unit.h"
#include "./src/pebble-extra.h"
#include "font-loader.h"

// Colour code definitions to make the output all pretty.
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

// Keep track of how many tests have run, and how many have passed.
int tests_run = 0;
int tests_passed = 0;
const int NUM_TESTS = 2;

static void before_each(void) {
  fonts_init();
}

static void after_each(void) {
  fonts_cleanup();
}

static char* test_id(void) {
  const uint32_t id = 123422;
  GFont font = fonts_get_font(id);
  mu_assert(NULL != font, "Loading font by ID returned NULL.");
  mu_assert(id == ((FakeFont*)font)->id, "Loading font by ID returned mismatched ID.");
  return 0;
}

static char* test_name(void) {
  const uint32_t id = 53818581;
  const char* name = "demo font";
  fonts_assign(name, id);
  GFont font = fonts_get_font_by_name(name);
  mu_assert(NULL != font, "Loading font by name returned NULL.");
  mu_assert(id == ((FakeFont*)font)->id, "Loading font by name returned mismatched ID.");
  return 0;
}

static char* all_tests() {
  mu_run_test(test_id);
  mu_run_test(test_name);
  return 0;
}

int main(int argc, char **argv) {
  printf("%s----------------------------\n", KCYN);
  printf("Running Font Loader Tests\n");
  printf("----------------------------\n%s", KNRM);
  char* result = all_tests();
  if (0 != result) {
    printf("%sFailed Test:%s %s\n", KRED, KNRM, result);
  }
  printf("Tests Run: %s%d / %d%s\n", (tests_run == NUM_TESTS) ? KGRN : KRED, tests_run, NUM_TESTS, KNRM);
  printf("Tests Passed: %s%d / %d%s\n", (tests_passed == NUM_TESTS) ? KGRN : KRED, tests_passed, NUM_TESTS, KNRM);

  printf("%s----------------------------%s\n", KCYN, KNRM);
  return result != 0;
}
