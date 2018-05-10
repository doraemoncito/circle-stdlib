//
// mqttpublisher.h
//
// Copyright (C) 2018  R. Stange <rsta2@o2online.de>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#ifndef _mqttpublisher_h
#define _mqttpublisher_h

#include <circle-mbedtls/mqttclient.h>
#include <circle/net/netsubsystem.h>
#include <circle/types.h>

namespace CircleMbedTLS
{

class CMQTTPublisher : public CMQTTClient
{
public:
	CMQTTPublisher (CNetSubSystem *pNetSubSystem);

	void OnConnect (boolean bSessionPresent);

	void OnDisconnect (TMQTTDisconnectReason Reason);

	void OnLoop (void);

private:
	float GetTemperature (void);

private:
	boolean m_bTimerRunning;
	unsigned m_nConnectTime;
	unsigned m_nLastPublishTime;
};

}

#endif
