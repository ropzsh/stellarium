/*
 * Copyright (C) 2020 Georg Zotti
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA  02110-1335, USA.
 */

#ifndef EGYPTIANCALENDAR_HPP
#define EGYPTIANCALENDAR_HPP

#include "Calendar.hpp"

//! This is the "Simple Calendar" exemplified in CC.UE chapter 1.11.
//! Epoch is the era of Nabonassar (Nebukadnezar)

class EgyptianCalendar : public Calendar
{
	Q_OBJECT

public:
	EgyptianCalendar(double jd);

	~EgyptianCalendar() override {}

public slots:
	void retranslate() override;

	//! Set a calendar date from the Julian day number
	void setJD(double JD) override;

	//! set date from a vector of calendar date elements sorted from the largest to the smallest.
	//! Year-Month[1...12]-Day[1...31]
	void setDate(const QVector<int> &parts) override;

	//! get a stringlist of calendar date elements sorted from the largest to the smallest.
	//! Year, Month, MonthName, Day, DayName
	QStringList getDateStrings() const override;

	//! get a formatted complete string for a date
	QString getFormattedDateString() const override;

	//! find RD number for date in the Egyptian calendar (may be used in other calendars!)
	static int fixedFromEgyptian(const QVector<int> &julian);
	//! find date in the Egyptian calendar from RD number (may be used in other calendars!)
	static QVector<int> egyptianFromFixed(int rd);

public:
	static const int egyptianEpoch; //! RD of JD1448638.

protected:
	static QMap<int, QString> monthNames;
};

#endif
