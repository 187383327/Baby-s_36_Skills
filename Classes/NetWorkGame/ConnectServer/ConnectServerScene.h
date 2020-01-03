#pragma once

#include "QE.h"

class ConnectServerScene : public Layer, public EditBoxDelegate, public NetworkBaseScene
{
	QE_SINGLETON_H(ConnectServerScene);
	QE_CreateSceneFromLayer_H(ConnectServerScene);
	NW_BaseScene;
public:
	static void dealServerResponse(int statusCode);
	static void disConnect();
private:
	static EditBox* _ip1Box, * _ip2Box, * _port1Box, * _port2Box, *_ip3Box, *_port3Box, * _ip4Box, * _port4Box, * _ip5Box, * _port5Box;

	void initLabel();

	void initMenu();

	void back();

	void initEditBox();

	void connect(int n);
};