//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST(GetWeatherTest, GetTemperature)
{
	WeatherMock WM;
	WM.SetApiKey("...");
	ASSERT_TRUE(std::abs(WM.GetTemperature("London") - 14.11) < 1e-5);
}

TEST(GetWeatherTest, DoubleDiff)
{
	WeatherMock WM;
	ASSERT_TRUE(std::abs(WM.FindDiffBetweenTwoCities("London", "Moscow") - (14.11 - 11.03)) < 1e-5);
	try
	{
		ASSERT_TRUE(std::abs(WM.FindDiffBetweenTwoCities("London", "Deli") - 0) < 1e-5);
		ASSERT_TRUE(false);
	}
	catch(std::invalid_argument& ia)
	{
	}
}

TEST(GetWeatherTest, StringDiff)
{
	WeatherMock WM;
	EXPECT_EQ(WM.GetDifferenceString("London", "Moscow"), 
		  "Weather in London is warmer than in Moscow by 3 degrees");
	EXPECT_EQ(WM.GetDifferenceString("Moscow", "London"),
		  "Weather in Moscow is colder than in London by 3 degrees");
}



TEST(GetWeatherTest, GetTomorrowTemperature)
{
	WeatherMock WM;
	ASSERT_TRUE(std::abs(WM.GetTomorrowTemperature("London") - 18.11) < 1e-5);
}

TEST(GetWeatherTest, GetTomorrowDiff)
{
	WeatherMock WM;
	EXPECT_EQ(WM.GetTomorrowDiff("London"),
		  "The weather in London tomorrow will be much warmer than today.");
	EXPECT_EQ(WM.GetTomorrowDiff("Moscow"),
		  "The weather in Moscow tomorrow will be warmer than today.");
	EXPECT_EQ(WM.GetTomorrowDiff("Pekin"),
		  "The weather in Pekin tomorrow will be the same than today.");
	EXPECT_EQ(WM.GetTomorrowDiff("Tokio"),
		  "The weather in Tokio tomorrow will be colder than today.");
	EXPECT_EQ(WM.GetTomorrowDiff("Washington"),
		  "The weather in Washington tomorrow will be much colder than today.");
}

