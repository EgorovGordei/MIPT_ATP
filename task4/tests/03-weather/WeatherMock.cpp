//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherMock.h"

std::string WeatherMock::GetStandartTodayResponse(double temperature)
{
	return "{\"main\":{\"temp\":" + std::to_string(temperature) + "}}";
}
std::string WeatherMock::GetStandartTomorrowResponse(double temperature)
{
	return "{\"list\":[{\"0\":0},{\"0\":0},{\"0\":0},{\"0\":0},{\"0\":0},{\"0\":0},{\"0\":0},{\"main\":{\"temp\":" + std::to_string(temperature) + "}}]}";
}

cpr::Response WeatherMock::Get(const std::string& city, const cpr::Url& url)
{
	std::string MY_API_KEY = "1816a69681c0e688e7e85349993b0aa8";
	std::string sresponse;
	int iresponse = 200;
	if (url[url.size() - 1] == 'r')
	{
		if (city == "London")
		{
			sresponse = WeatherMock::GetStandartTodayResponse(14.11);
		}
		else if (city == "Moscow")
		{
			sresponse = WeatherMock::GetStandartTodayResponse(11.03);
		}
		else if (city == "Pekin")
		{
			sresponse = WeatherMock::GetStandartTodayResponse(29.01);
		}
		else if (city == "Tokio")
		{
			sresponse = WeatherMock::GetStandartTodayResponse(1.0);
		}
		else if (city == "Washington")
		{
			sresponse = WeatherMock::GetStandartTodayResponse(-1.0);
		}
		else
		{
			iresponse = 404;
			sresponse = WeatherMock::GetStandartTodayResponse(0.0);
		}
	}
	else
	{
		if (city == "London")
		{
			sresponse = WeatherMock::GetStandartTomorrowResponse(18.11);
		}
		else if (city == "Moscow")
		{
			sresponse = WeatherMock::GetStandartTomorrowResponse(12.03);
		}
		else if (city == "Pekin")
		{
			sresponse = WeatherMock::GetStandartTomorrowResponse(29.03);
		}
		else if (city == "Tokio")
		{
			sresponse = WeatherMock::GetStandartTomorrowResponse(0);
		}
		else if (city == "Washington")
		{
			sresponse = WeatherMock::GetStandartTomorrowResponse(-5.0);
		}
		else
		{
			iresponse = 404;
			sresponse = WeatherMock::GetStandartTomorrowResponse(0.0);
		}
	}
	cpr::Response response(iresponse, std::move(sresponse), 
			       cpr::Header{}, std::move(url), 1.0, cpr::Cookies{}, cpr::Error{});
	return response;
}

