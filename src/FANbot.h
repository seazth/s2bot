#pragma once

#include "sc2api/sc2_interfaces.h"
#include "sc2api/sc2_agent.h"
#include "sc2api/sc2_map_info.h"
#include "sc2lib/sc2_lib.h"

#include "Strategys.h"
#define DllExport   __declspec( dllexport )  
using namespace sc2;

#define MAX_GEASER_DISTANCE 200

class FANbot : public Agent
{
public:
	FANbot();
	virtual void OnGameStart() override;
	virtual void OnStep() override;
	virtual void OnUnitIdle(const Unit *unit) override;
	virtual void OnUnitDestroyed(const Unit *unit) override;
	virtual void OnUnitCreated(const Unit *unit) override;
	virtual void OnUnitEnterVision(const Unit *unit) override;
	bool BuildAvailableGeaser(AbilityID build_ability, UnitTypeID worker_type, Point2D base_location);

private:
	sc2::Point3D *StartPosition;
	sc2::Point2D RushLocation;
	std::vector<Point3D> expansions_; // toutes les cases du terrain
	void SetupRushLocation(const ObservationInterface *observation);
	GameInfo *game_info_;
	sc2::Race OpponentRace;
	//
	bool TryBuildStructure(ABILITY_ID ability_type_for_structure, UNIT_TYPEID unit_type = UNIT_TYPEID::TERRAN_SCV);
	bool TryBuildSupplyDepot();
	const Unit* FANbot::FindNearest(UNIT_TYPEID typeId, const Point2D& start);
	size_t CountUnitType(UNIT_TYPEID unit_type);
	bool TryBuildBarracks();
	bool TryBuildRefinery();
	bool TryBuildStructureByTag(AbilityID ability_type_for_structure, UnitTypeID unit_type, Tag location_tag);
	bool TryBuildFactory();
	void TryToExpand(const Unit* unit);

	std::vector<const sc2::Unit *> defenders;
	std::vector<const sc2::Unit *> attackers;
};


void DllExport *CreateNewAgent();

int DllExport GetAgentRace();

const char DllExport *GetAgentName();