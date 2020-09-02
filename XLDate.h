#ifndef DATEWRAPPER_H
#define DATEWRAPPER_H

#include "date.h"
#include <iostream>

using namespace date::literals;		// Exception to the general rule

namespace Dates
{
	class XLDate
	{
	public:
		XLDate();
		XLDate(unsigned serialDate);								// throws out_of_range
		XLDate(unsigned year, unsigned month, unsigned day);		// throws out_of_range

		// We should maybe make these binary friend functions:
		XLDate& addYears(int years);
		XLDate& addMonths(int months);
		XLDate& addDays(int days);

		unsigned daysInMonth() const;
		unsigned dayOfWeek() const;		// What is the day of the week (1-7, or 0-6)
										// Needs implementation
		bool endOfMonth() const;
		bool leapYear() const;			// Is the date in a leap year
		bool weekday() const;			// Is the date on a weekday (Needs implementation)

		unsigned year() const;
		unsigned month() const;
		unsigned day() const;
		unsigned serialDate() const;

		void setYear(unsigned year);
		void setMonth(unsigned month);
		void setDay(unsigned day);
		void setSerialDate(unsigned serialDate);

		unsigned operator()() const;		// Alternative accessor for serialDate_
		unsigned operator - (const XLDate& rhs) const;

		XLDate& operator += (int days);
		XLDate& operator -= (int days);

		XLDate& operator ++ ();
		XLDate& operator -- ();

		XLDate operator ++ (int notused);
		XLDate operator -- (int notused);

		bool operator == (const XLDate& rhs) const;
		bool operator != (const XLDate& rhs) const;
		bool operator < (const XLDate& rhs) const;
		bool operator > (const XLDate& rhs) const;
		bool operator <= (const XLDate& rhs) const;
		bool operator >= (const XLDate& rhs) const;

		// friend operator so that we can output date details with cout
		friend std::ostream& operator << (std::ostream& os, const XLDate& rhs);

	private:
		bool serialToDate_();
		bool dateToSerial_();

		unsigned serialDate_;
		date::year_month_day date_;

		// This can only be done in the header for integer types (prior to C++11)
		static const unsigned minSerial_ = 1;		// 1900.01.01: Matches Excel
		static const unsigned maxSerial_ = 109574;	// 2199.12.31: Matches Excel
		static constexpr date::sys_days minDate_ = date::sys_days(1900_y / jan / 01);
		static constexpr date::sys_days maxDate_ = date::sys_days(2199_y / dec / 31);
	};
};

#endif

/*
	The MIT License (MIT)

	Copyright (c) 2020 Daniel Hanson
	Contributors: Reeta Khare, Gregory Brownson, Steven Zhang

	Permission is hereby granted, free of charge, to any person obtaining a copy of this software
	and associated documentation files (the "Software"), to deal in the Software without restriction,
	including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
	and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
	subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or substantial
	portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
	NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
	IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
	SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/