//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include <Weather.h>

class WeatherMock : public Weather {
private:
	static std::string GetStandartTodayResponse(double temperature);
	static std::string GetStandartTomorrowResponse(double temperature);
	virtual cpr::Response Get(const std::string& city, const cpr::Url& url) override;
};



