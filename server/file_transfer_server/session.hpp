#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include "internal_exception.hpp"
#include "protocol/request_header.hpp"
#include "protocol/response_header.hpp"

class Session
{
public:
	Session(boost::asio::ip::tcp::socket);
	static void run(boost::asio::ip::tcp::socket);

private:
	void handle_request();
	Protocol::InternalRequest parse_request();
	Protocol::InternalResponse execute_request(const Protocol::InternalRequest&);
	void write_response(Protocol::InternalResponse);

	boost::asio::ip::tcp::socket client_socket;
};
