include(FetchContent)
# clone gtest build and install it 
fetchcontent_declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
)
fetchcontent_makeavailable(googletest)