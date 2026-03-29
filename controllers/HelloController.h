#pragma once
#include <deque>
#include <drogon/HttpController.h>
#include <mutex>
#include <string>

using namespace drogon;

class HelloController : public HttpController<HelloController> // ? notice, uses CRTP style
{
  private:
	std::deque<std::pair<std::string, std::string>> m_visitors;
	std::mutex m_visitorMutex;

  public:
	METHOD_LIST_BEGIN
	ADD_METHOD_TO(HelloController::sayHello, "/hello/{name}", Get);
	ADD_METHOD_TO(HelloController::saySecretHello, "/hello-key/{name}", Get, "MyLoggingFilter");
	ADD_METHOD_TO(HelloController::renderHelloPage, "/hello-page/{name}", Get);
	ADD_METHOD_TO(HelloController::renderHelloVisitors, "/visitors", Get);
	METHOD_LIST_END

	void sayHello(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, std::string name);
	void saySecretHello(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
						std::string name);
	void renderHelloPage(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
						 std::string name);
	void renderHelloVisitors(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
};