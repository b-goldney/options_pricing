#include "DayCount.h"
#include "XLDate.h"

using Dates::XLDate;

namespace Dates
{
	/*
		Excel's Actual/Actual calculation is known to be incorrect.  We don't 
		need it right away, so we'll hold it in abeyance for now.	
	*/
	
	// *** Class Thirty360 ***
	// This is the **ISDA** 30/360  daycount.
	// See https://www.iso20022.org/15022/uhb/mt565-16-field-22f.htm and
	// http://kalotay.com/SupportingDocumentation/BondOAS/daycounts.html (30/360 ISDA)
	// There are discrepancies with the Excel function YEARFRAC(fromDate; toDate; 0),
	// but Excel might have implemented a different 30/360 rule (to be investigated)
	double Thirty360::operator()(const XLDate& date1, const XLDate& date2) const
	{
		return yearFraction(date1, date2);
	}

	double Thirty360::yearFraction(const XLDate& date1, const XLDate& date2) const
	{
		return static_cast<double>(dateDiff_(date1, date2)) / 360.0;
	}


	unsigned Thirty360::dateDiff_(const XLDate& date1, const XLDate& date2) const
	{
		unsigned d1, d2;
		d1 = date1.day();
		d2 = date2.day();
			
		if(d1 == 31) d1 = 30;

		// Actual rule is conditioned on d1 being 30 *or* 31,
		// but the case of 31 was already adjusted in the previous command
		if ((d2 == 31) && (d1 == 30)) d2 = 30;

		return 360 * (date2.year() - date1.year()) + 30 * (date2.month() - date1.month()) + d2 - d1;
	}


	// *** Class Thirty360Eur ***; see https://sqlsunday.com/2014/08/17/30-360-day-count-convention/
	double Thirty360Eur::operator()(const XLDate& date1, const XLDate& date2) const
	{
		return yearFraction(date1, date2);
	}

	double Thirty360Eur::yearFraction(const XLDate& date1, const XLDate& date2) const
	{

		return static_cast<double>(dateDiff_(date1, date2)) / 360.0;
	}

	unsigned Thirty360Eur::dateDiff_(const XLDate& date1, const XLDate& date2) const
	{
		unsigned d1, d2;
		d1 = date1.day();
		d2 = date2.day();

		auto f = [](unsigned& d) {
			if (d == 31)
			{
				d = 30;
			}
		};

		f(d1);
		f(d2);

		return 360 * (date2.year() - date1.year()) + 30 * (date2.month() - date1.month()) + d2 - d1;
	}

	// *** Class Act365 Fixed ***
	double Act365::operator()(const XLDate& date1, const XLDate& date2) const
	{
		return yearFraction(date1, date2);
	}

	double Act365::yearFraction(const XLDate& date1, const XLDate& date2) const
	{
		return (date2 - date1) / 365.0;
	}


	// *** Class Act360 ***
	double Act360::operator()(const XLDate& date1, const XLDate& date2) const
	{
		return yearFraction(date1, date2);
	}

	double Act360::yearFraction(const XLDate& date1, const XLDate& date2) const
	{
		return (date2 - date1) / 360.0;
	}
}	// namespace Dates

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