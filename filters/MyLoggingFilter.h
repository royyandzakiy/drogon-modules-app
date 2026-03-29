#pragma once
#include <drogon/HttpFilter.h>
#include <print>

using namespace drogon;

class MyLoggingFilter : public HttpFilter<MyLoggingFilter> {
  public:
	void doFilter(const HttpRequestPtr &req, FilterCallback &&fcb, FilterChainCallback &&fccb) override;
};