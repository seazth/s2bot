#include <iostream>

#include "FANbot.h"
#include "sc2api/sc2_api.h"

using namespace std;

struct IsAttackable {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::ZERG_OVERLORD: return false;
		case UNIT_TYPEID::ZERG_OVERSEER: return false;
		case UNIT_TYPEID::PROTOSS_OBSERVER: return false;
		default: return true;
		}
	}
};
struct IsBuilding {
	bool operator()(const sc2::Unit & unit)
	{
		switch (unit.unit_type.ToType())
		{
		case sc2::UNIT_TYPEID::TERRAN_ARMORY:           return true;
		case sc2::UNIT_TYPEID::PROTOSS_ASSIMILATOR:     return true;
		case sc2::UNIT_TYPEID::ZERG_BANELINGNEST:       return true;
		case sc2::UNIT_TYPEID::TERRAN_BARRACKS:         return true;
		case sc2::UNIT_TYPEID::TERRAN_BARRACKSREACTOR:  return true;
		case sc2::UNIT_TYPEID::TERRAN_BARRACKSTECHLAB:  return true;
		case sc2::UNIT_TYPEID::TERRAN_BUNKER:           return true;
		case sc2::UNIT_TYPEID::TERRAN_COMMANDCENTER:    return true;
		case sc2::UNIT_TYPEID::PROTOSS_CYBERNETICSCORE: return true;
		case sc2::UNIT_TYPEID::PROTOSS_DARKSHRINE:      return true;
		case sc2::UNIT_TYPEID::TERRAN_ENGINEERINGBAY:   return true;
		case sc2::UNIT_TYPEID::ZERG_EVOLUTIONCHAMBER:   return true;
		case sc2::UNIT_TYPEID::ZERG_EXTRACTOR:          return true;
		case sc2::UNIT_TYPEID::TERRAN_FACTORY:          return true;
		case sc2::UNIT_TYPEID::TERRAN_FACTORYREACTOR:   return true;
		case sc2::UNIT_TYPEID::TERRAN_FACTORYTECHLAB:   return true;
		case sc2::UNIT_TYPEID::PROTOSS_FLEETBEACON:     return true;
		case sc2::UNIT_TYPEID::PROTOSS_FORGE:           return true;
		case sc2::UNIT_TYPEID::TERRAN_FUSIONCORE:       return true;
		case sc2::UNIT_TYPEID::PROTOSS_GATEWAY:         return true;
		case sc2::UNIT_TYPEID::PROTOSS_WARPGATE:        return true;
		case sc2::UNIT_TYPEID::TERRAN_GHOSTACADEMY:     return true;
		case sc2::UNIT_TYPEID::ZERG_HATCHERY:           return true;
		case sc2::UNIT_TYPEID::ZERG_HYDRALISKDEN:       return true;
		case sc2::UNIT_TYPEID::ZERG_INFESTATIONPIT:     return true;
		case sc2::UNIT_TYPEID::TERRAN_MISSILETURRET:    return true;
		case sc2::UNIT_TYPEID::PROTOSS_NEXUS:           return true;
		case sc2::UNIT_TYPEID::ZERG_NYDUSCANAL:         return true;
		case sc2::UNIT_TYPEID::ZERG_NYDUSNETWORK:       return true;
		case sc2::UNIT_TYPEID::PROTOSS_PHOTONCANNON:    return true;
		case sc2::UNIT_TYPEID::PROTOSS_PYLON:           return true;
		case sc2::UNIT_TYPEID::TERRAN_REFINERY:         return true;
		case sc2::UNIT_TYPEID::ZERG_ROACHWARREN:        return true;
		case sc2::UNIT_TYPEID::PROTOSS_ROBOTICSBAY:     return true;
		case sc2::UNIT_TYPEID::PROTOSS_ROBOTICSFACILITY: return true;
		case sc2::UNIT_TYPEID::TERRAN_SENSORTOWER:      return true;
		case sc2::UNIT_TYPEID::ZERG_SPAWNINGPOOL:       return true;
		case sc2::UNIT_TYPEID::ZERG_SPINECRAWLER:       return true;
		case sc2::UNIT_TYPEID::ZERG_SPIRE:              return true;
		case sc2::UNIT_TYPEID::ZERG_SPORECRAWLER:       return true;
		case sc2::UNIT_TYPEID::PROTOSS_STARGATE:        return true;
		case sc2::UNIT_TYPEID::TERRAN_STARPORT:         return true;
		case sc2::UNIT_TYPEID::TERRAN_STARPORTREACTOR:  return true;
		case sc2::UNIT_TYPEID::TERRAN_STARPORTTECHLAB:  return true;
		case sc2::UNIT_TYPEID::TERRAN_SUPPLYDEPOT:      return true;
		case sc2::UNIT_TYPEID::PROTOSS_TEMPLARARCHIVE:  return true;
		case sc2::UNIT_TYPEID::PROTOSS_TWILIGHTCOUNCIL: return true;
		case sc2::UNIT_TYPEID::ZERG_ULTRALISKCAVERN:    return true;
		case sc2::UNIT_TYPEID::ZERG_HIVE:               return true;
		case sc2::UNIT_TYPEID::ZERG_LAIR:               return true;
		case sc2::UNIT_TYPEID::ZERG_GREATERSPIRE:       return true;
		case sc2::UNIT_TYPEID::TERRAN_ORBITALCOMMAND:   return true;
		case sc2::UNIT_TYPEID::TERRAN_PLANETARYFORTRESS: return true;
		case sc2::UNIT_TYPEID::TERRAN_SUPPLYDEPOTLOWERED: return true;
		case sc2::UNIT_TYPEID::TERRAN_FACTORYFLYING:	return true;
		case sc2::UNIT_TYPEID::TERRAN_BARRACKSFLYING:	return true;
		case sc2::UNIT_TYPEID::TERRAN_COMMANDCENTERFLYING: return true;
		case sc2::UNIT_TYPEID::TERRAN_ORBITALCOMMANDFLYING: return true;
		case sc2::UNIT_TYPEID::TERRAN_STARPORTFLYING:	return true;
		case sc2::UNIT_TYPEID::TERRAN_TECHLAB:			return true;

		default: return false;
		}
	}
};

struct IsArmy {
	bool operator()(const sc2::Unit & unit)
	{
		switch (unit.unit_type.ToType())
		{
		case UNIT_TYPEID::TERRAN_BANSHEE: return true;
		case UNIT_TYPEID::TERRAN_BATTLECRUISER: return true;
		case UNIT_TYPEID::TERRAN_CYCLONE: return true;
		case UNIT_TYPEID::TERRAN_GHOST: return true;
		case UNIT_TYPEID::TERRAN_HELLION: return true;
		case UNIT_TYPEID::TERRAN_HELLIONTANK: return true;
		case UNIT_TYPEID::TERRAN_LIBERATOR: return true;
		case UNIT_TYPEID::TERRAN_LIBERATORAG: return true;
		case UNIT_TYPEID::TERRAN_MARAUDER: return true;
		case UNIT_TYPEID::TERRAN_MARINE: return true;
		case UNIT_TYPEID::TERRAN_MEDIVAC: return true;
		case UNIT_TYPEID::TERRAN_MULE: return true;
		case UNIT_TYPEID::TERRAN_RAVEN: return true;
		case UNIT_TYPEID::TERRAN_REAPER: return true;
		case UNIT_TYPEID::TERRAN_SCV: return true;
		case UNIT_TYPEID::TERRAN_SIEGETANK: return true;
		case UNIT_TYPEID::TERRAN_SIEGETANKSIEGED: return true;
		case UNIT_TYPEID::TERRAN_THOR: return true;
		case UNIT_TYPEID::TERRAN_THORAP: return true;
		case UNIT_TYPEID::TERRAN_VIKINGASSAULT: return true;
		case UNIT_TYPEID::TERRAN_VIKINGFIGHTER: return true;
		case UNIT_TYPEID::ZERG_BANELING: return true;
		case UNIT_TYPEID::ZERG_BROODLING: return true;
		case UNIT_TYPEID::ZERG_BROODLORD: return true;
		case UNIT_TYPEID::ZERG_BROODLORDCOCOON: return true;
		case UNIT_TYPEID::ZERG_CHANGELING: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGMARINE: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGMARINESHIELD: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGZEALOT: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGZERGLING: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGZERGLINGWINGS: return true;
		case UNIT_TYPEID::ZERG_CORRUPTOR: return true;
		case UNIT_TYPEID::ZERG_DRONE: return true;
		case UNIT_TYPEID::ZERG_HYDRALISK: return true;
		case UNIT_TYPEID::ZERG_INFESTEDTERRANSEGG: return true;
		case UNIT_TYPEID::ZERG_INFESTOR: return true;
		case UNIT_TYPEID::ZERG_INFESTORTERRAN: return true;
		case UNIT_TYPEID::ZERG_LOCUSTMP: return true;
		case UNIT_TYPEID::ZERG_LOCUSTMPFLYING: return true;
		case UNIT_TYPEID::ZERG_LURKERMP: return true;
		case UNIT_TYPEID::ZERG_MUTALISK: return true;
		case UNIT_TYPEID::ZERG_OVERLORD: return true;
		case UNIT_TYPEID::ZERG_OVERLORDTRANSPORT: return true;
		case UNIT_TYPEID::ZERG_OVERSEER: return true;
		case UNIT_TYPEID::ZERG_QUEEN: return true;
		case UNIT_TYPEID::ZERG_RAVAGER: return true;
		case UNIT_TYPEID::ZERG_ROACH: return true;
		case UNIT_TYPEID::ZERG_SPINECRAWLERUPROOTED: return true;
		case UNIT_TYPEID::ZERG_SPORECRAWLERUPROOTED: return true;
		case UNIT_TYPEID::ZERG_SWARMHOSTBURROWEDMP: return true;
		case UNIT_TYPEID::ZERG_SWARMHOSTMP: return true;
		case UNIT_TYPEID::ZERG_TRANSPORTOVERLORDCOCOON: return true;
		case UNIT_TYPEID::ZERG_ULTRALISK: return true;
		case UNIT_TYPEID::ZERG_VIPER: return true;
		case UNIT_TYPEID::ZERG_ZERGLING: return true;
		case UNIT_TYPEID::PROTOSS_ADEPT: return true;
		case UNIT_TYPEID::PROTOSS_ARCHON: return true;
		case UNIT_TYPEID::PROTOSS_CARRIER: return true;
		case UNIT_TYPEID::PROTOSS_COLOSSUS: return true;
		case UNIT_TYPEID::PROTOSS_DARKTEMPLAR: return true;
		case UNIT_TYPEID::PROTOSS_DISRUPTOR: return true;
		case UNIT_TYPEID::PROTOSS_HIGHTEMPLAR: return true;
		case UNIT_TYPEID::PROTOSS_IMMORTAL: return true;
		case UNIT_TYPEID::PROTOSS_INTERCEPTOR: return true;
		case UNIT_TYPEID::PROTOSS_MOTHERSHIP: return true;
		case UNIT_TYPEID::PROTOSS_MOTHERSHIPCORE: return true;
		case UNIT_TYPEID::PROTOSS_OBSERVER: return true;
		case UNIT_TYPEID::PROTOSS_ORACLE: return true;
		case UNIT_TYPEID::PROTOSS_PHOENIX: return true;
		case UNIT_TYPEID::PROTOSS_PROBE: return true;
		case UNIT_TYPEID::PROTOSS_SENTRY: return true;
		case UNIT_TYPEID::PROTOSS_STALKER: return true;
		case UNIT_TYPEID::PROTOSS_TEMPEST: return true;
		case UNIT_TYPEID::PROTOSS_VOIDRAY: return true;
		case UNIT_TYPEID::PROTOSS_WARPPRISM: return true;
		case UNIT_TYPEID::PROTOSS_ZEALOT: return true;
		default: return false;
		}
	}
};

struct IsGroundArmy {
	bool operator()(const sc2::Unit & unit)
	{
		switch (unit.unit_type.ToType())
		{
		case UNIT_TYPEID::TERRAN_BANSHEE: return true;
		case UNIT_TYPEID::TERRAN_BATTLECRUISER: return true;
		case UNIT_TYPEID::TERRAN_CYCLONE: return true;
		case UNIT_TYPEID::TERRAN_GHOST: return true;
		case UNIT_TYPEID::TERRAN_HELLION: return true;
		case UNIT_TYPEID::TERRAN_HELLIONTANK: return true;
		case UNIT_TYPEID::TERRAN_MARAUDER: return true;
		case UNIT_TYPEID::TERRAN_MARINE: return true;
		case UNIT_TYPEID::TERRAN_MULE: return true;
		case UNIT_TYPEID::TERRAN_REAPER: return true;
		case UNIT_TYPEID::TERRAN_SCV: return true;
		case UNIT_TYPEID::TERRAN_SIEGETANK: return true;
		case UNIT_TYPEID::TERRAN_SIEGETANKSIEGED: return true;
		case UNIT_TYPEID::TERRAN_THOR: return true;
		case UNIT_TYPEID::TERRAN_THORAP: return true;
		case UNIT_TYPEID::TERRAN_VIKINGASSAULT: return true;
		case UNIT_TYPEID::ZERG_BANELING: return true;
		case UNIT_TYPEID::ZERG_BROODLING: return true;
		case UNIT_TYPEID::ZERG_BROODLORDCOCOON: return true;
		case UNIT_TYPEID::ZERG_CHANGELING: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGMARINE: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGMARINESHIELD: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGZEALOT: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGZERGLING: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGZERGLINGWINGS: return true;
		case UNIT_TYPEID::ZERG_CORRUPTOR: return true;
		case UNIT_TYPEID::ZERG_DRONE: return true;
		case UNIT_TYPEID::ZERG_HYDRALISK: return true;
		case UNIT_TYPEID::ZERG_INFESTEDTERRANSEGG: return true;
		case UNIT_TYPEID::ZERG_INFESTOR: return true;
		case UNIT_TYPEID::ZERG_INFESTORTERRAN: return true;
		case UNIT_TYPEID::ZERG_LURKERMP: return true;
		case UNIT_TYPEID::ZERG_OVERLORD: return true;
		case UNIT_TYPEID::ZERG_OVERLORDTRANSPORT: return true;
		case UNIT_TYPEID::ZERG_OVERSEER: return true;
		case UNIT_TYPEID::ZERG_QUEEN: return true;
		case UNIT_TYPEID::ZERG_RAVAGER: return true;
		case UNIT_TYPEID::ZERG_ROACH: return true;
		case UNIT_TYPEID::ZERG_SPINECRAWLERUPROOTED: return true;
		case UNIT_TYPEID::ZERG_SPORECRAWLERUPROOTED: return true;
		case UNIT_TYPEID::ZERG_SWARMHOSTBURROWEDMP: return true;
		case UNIT_TYPEID::ZERG_SWARMHOSTMP: return true;
		case UNIT_TYPEID::ZERG_TRANSPORTOVERLORDCOCOON: return true;
		case UNIT_TYPEID::ZERG_ULTRALISK: return true;
		case UNIT_TYPEID::ZERG_ZERGLING: return true;
		case UNIT_TYPEID::PROTOSS_ADEPT: return true;
		case UNIT_TYPEID::PROTOSS_ARCHON: return true;
		case UNIT_TYPEID::PROTOSS_COLOSSUS: return true;
		case UNIT_TYPEID::PROTOSS_DARKTEMPLAR: return true;
		case UNIT_TYPEID::PROTOSS_DISRUPTOR: return true;
		case UNIT_TYPEID::PROTOSS_HIGHTEMPLAR: return true;
		case UNIT_TYPEID::PROTOSS_IMMORTAL: return true;
		case UNIT_TYPEID::PROTOSS_PROBE: return true;
		case UNIT_TYPEID::PROTOSS_SENTRY: return true;
		case UNIT_TYPEID::PROTOSS_STALKER: return true;
		case UNIT_TYPEID::PROTOSS_ZEALOT: return true;
		default: return false;
		}
	}
};


struct IsTownHall {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::ZERG_HATCHERY: return true;
		case UNIT_TYPEID::ZERG_LAIR: return true;
		case UNIT_TYPEID::ZERG_HIVE: return true;
		case UNIT_TYPEID::TERRAN_COMMANDCENTER: return true;
		case UNIT_TYPEID::TERRAN_ORBITALCOMMAND: return true;
		case UNIT_TYPEID::TERRAN_ORBITALCOMMANDFLYING: return true;
		case UNIT_TYPEID::TERRAN_PLANETARYFORTRESS: return true;
		case UNIT_TYPEID::PROTOSS_NEXUS: return true;
		default: return false;
		}
	}
};

struct IsVespeneGeyser {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::NEUTRAL_VESPENEGEYSER: return true;
		case UNIT_TYPEID::NEUTRAL_SPACEPLATFORMGEYSER: return true;
		case UNIT_TYPEID::NEUTRAL_PROTOSSVESPENEGEYSER: return true;
		default: return false;
		}
	}
};

struct IsWorker {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::PROTOSS_PROBE: return true;
		case UNIT_TYPEID::ZERG_DRONE: return true;
		case UNIT_TYPEID::TERRAN_SCV: return true;
		default: return false;
		}
	}
};

FANbot::FANbot() {

}

void FANbot::OnGameStart() {
	Actions()->SendChat("gl hf !");

	const Units NewUnits = Observation()->GetUnits();
	for (auto &u : NewUnits)
	{
		if (u->unit_type == UNIT_TYPEID::TERRAN_COMMANDCENTER)
		{
			StartPosition = new sc2::Point3D(u->pos);
			Actions()->UnitCommand(u, ABILITY_ID::TRAIN_PROBE);
			break;
		}
	}

	game_info_ = new sc2::GameInfo(Observation()->GetGameInfo());
	bool OwnRaceFound = false;
	for (const auto &info : game_info_->player_info)
	{
		if (info.race_actual == sc2::Race::Protoss && OwnRaceFound == false)
		{
			OwnRaceFound = true;
			continue;
		}
		OpponentRace = info.race_actual;
	}
	SetupRushLocation(Observation());
}

void FANbot::SetupRushLocation(const ObservationInterface *observation)
{
	if (StartPosition == nullptr || (StartPosition->x == 0 && StartPosition->y == 0 && StartPosition->z == 0))
	{
		return;
	}
	Point2D Point1;
	Point2D Point2;
	if (game_info_->map_name.compare("Ascension to Aiur LE") == 0)
	{
		Point1 = Point2D(33.397f, 119.001f);//, 10.0061f);
		Point2 = Point2D(142.58f, 32.9744f);//, 10.0032f);
	}
	else if (game_info_->map_name.compare("Proxima Station LE") == 0)
	{
		Point1 = Point2D(55.5349f, 45.8899f);//, 12.0083f);
		Point2 = Point2D(144.946f, 119.996f);//, 12.0068f);
	}
	else if (game_info_->map_name.compare("Mech Depot LE") == 0)
	{
		Point1 = Point2D(144.891f, 126.548f);//, 9.99219f);
		Point2 = Point2D(38.4912f, 36.8269f);//, 10.0034f);
	}
	else if (game_info_->map_name.compare("Odyssey LE") == 0)
	{
		Point1 = Point2D(140.301f, 46.1042f);//, 10.0193f);
		Point2 = Point2D(29.7517f, 123.95f);//, 9.99219f);
	}
	else if (game_info_->map_name.compare("Abyssal Reef LE") == 0)
	{
		Point1 = Point2D(51.3499f, 119.31f);//, 9.98828f);
		Point2 = Point2D(148.648f, 24.686f);//, 9.98828f);
	}
	else if (game_info_->map_name.compare("Interloper LE") == 0)
	{
		Point1 = Point2D(113.626f, 43.3684f);
		Point2 = Point2D(40.6443f, 130.659f);
	}
	else if (game_info_->map_name.compare("Blackpink LE") == 0)
	{
		Point1 = Point2D(144.061f, 122.754f);
		Point2 = Point2D(24.4409f, 37.0681f);
	}
	else if (game_info_->map_name.compare("Acolyte LE") == 0)
	{
		Point1 = Point2D(123.395f, 160.331f);
		Point2 = Point2D(48.7954f, 23.0759f);
	}
	else
	{
		return;
	}
	if (Distance2D(*StartPosition, Point1) > Distance2D(*StartPosition, Point2))
	{
		RushLocation = Point1;
	}
	else
	{
		RushLocation = Point2;
	}
}

void FANbot::OnStep() {
	const ObservationInterface* observation = Observation();
	if (!observation)
	{
		return;
	}
	const GameInfo& game_info = Observation()->GetGameInfo();

	TryBuildSupplyDepot();
	TryBuildRefinery();
	if (CountUnitType(UNIT_TYPEID::TERRAN_BARRACKS) < 5) {
		TryBuildBarracks();
	}
	else if (CountUnitType(UNIT_TYPEID::TERRAN_FACTORY) < 1) {
		TryBuildFactory();
	}

	if (CountUnitType(UNIT_TYPEID::TERRAN_MARINE) == 40) {
		Units marines = observation->GetUnits(Unit::Alliance::Self, IsUnit(UNIT_TYPEID::TERRAN_MARINE));
		Actions()->UnitCommand(marines, ABILITY_ID::ATTACK_ATTACK, game_info.enemy_start_locations.front());
	}
}

void FANbot::OnUnitIdle(const Unit *unit) {
	switch (unit->unit_type.ToType()) {
		case UNIT_TYPEID::TERRAN_COMMANDCENTER: {
			if (unit->assigned_harvesters < unit->ideal_harvesters) {
				Actions()->UnitCommand(unit, ABILITY_ID::TRAIN_SCV);
			}
			else if (Observation()->GetMinerals() >= 150) {
				Actions()->UnitCommand(unit, ABILITY_ID::MORPH_ORBITALCOMMAND);
			}
			break;
		}
		case UNIT_TYPEID::TERRAN_ORBITALCOMMAND: {
			if (unit->assigned_harvesters < unit->ideal_harvesters) {
				Actions()->UnitCommand(unit, ABILITY_ID::TRAIN_SCV);
			}
		}
		case UNIT_TYPEID::TERRAN_SCV: {
			const Unit* mineral_target = FindNearestMineralPatch(unit->pos);
			Units bases = Observation()->GetUnits(Unit::Alliance::Self, IsTownHall());
			Units AllGeasers = Observation()->GetUnits(Unit::Alliance::Self, IsUnit(UNIT_TYPEID::TERRAN_REFINERY));

			if (!mineral_target) {
				break;
			}
			for (const auto& geyser : AllGeasers) {
				if (geyser->assigned_harvesters < geyser->ideal_harvesters) {
					Actions()->UnitCommand(unit, ABILITY_ID::HARVEST_GATHER, geyser);
					break;
				}
				else {
					Actions()->UnitCommand(unit, ABILITY_ID::HARVEST_GATHER, mineral_target);
					break;
				}
			}
			break;
		}
		case UNIT_TYPEID::TERRAN_BARRACKS: {
			if (CountUnitType(UNIT_TYPEID::TERRAN_BARRACKSTECHLAB) == 0) {
				Actions()->UnitCommand(unit, ABILITY_ID::BUILD_TECHLAB_BARRACKS);
			}
			else {
				Actions()->UnitCommand(unit, ABILITY_ID::BUILD_REACTOR);
				Actions()->UnitCommand(unit, ABILITY_ID::TRAIN_MARINE);
				Actions()->UnitCommand(unit, ABILITY_ID::TRAIN_MARINE);
			}
			break;
		}
		case UNIT_TYPEID::TERRAN_BARRACKSTECHLAB: {
			Actions()->UnitCommand(unit, ABILITY_ID::RESEARCH_COMBATSHIELD);
			break;
		}
		case UNIT_TYPEID::TERRAN_FACTORY: {
			if (CountUnitType(UNIT_TYPEID::TERRAN_FACTORYTECHLAB) == 0) {
				Actions()->UnitCommand(unit, ABILITY_ID::BUILD_TECHLAB);
			}
			Actions()->UnitCommand(unit, ABILITY_ID::TRAIN_SIEGETANK);
			break;
		}
		/*case UNIT_TYPEID::TERRAN_MARINE: {
			const GameInfo& game_info = Observation()->GetGameInfo();
			Actions()->UnitCommand(unit, ABILITY_ID::ATTACK_ATTACK, game_info.enemy_start_locations.front());
			break;
		}*/
		default: {
			break;
		}
	}
}

void FANbot::OnUnitDestroyed(const Unit *unit) {
	
}

void FANbot::OnUnitCreated(const Unit *unit) {

}

void FANbot::OnUnitEnterVision(const Unit *unit) {
	
}

bool FANbot::TryBuildStructure(ABILITY_ID ability_type_for_structure, UNIT_TYPEID unit_type) {
	const ObservationInterface* observation = Observation();

	// If a unit already is building a supply structure of this type, do nothing.
	// Also get an scv to build the structure.
	const Unit* unit_to_build = nullptr;
	Units units = observation->GetUnits(Unit::Alliance::Self);
	for (const auto& unit : units) {
		for (const auto& order : unit->orders) {
			if (order.ability_id == ability_type_for_structure) {
				return false;
			}
		}

		if (unit->unit_type == unit_type) {
			unit_to_build = unit;
		}
	}
	float rx, ry = 0.0f;
	float scaleX, scaleY = 0.0f;
	if (Observation()->GetGameInfo().start_locations.front().x < 30) {
		rx = CountUnitType(UNIT_TYPEID::TERRAN_BARRACKS) % 2 == 0 ? GetRandomFraction() : -GetRandomFraction();//GetRandomScalar();
		ry = CountUnitType(UNIT_TYPEID::TERRAN_BARRACKS) % 2 == 0 ? GetRandomFraction() : -GetRandomFraction();//GetRandomScalar();
		scaleX = GetRandomInteger(30, 45); //25.0f;
		scaleY = GetRandomInteger(40, 60);//30.0f;
	}
	else {
		rx = CountUnitType(UNIT_TYPEID::TERRAN_BARRACKS) % 2 == 0 ? -GetRandomFraction() : GetRandomFraction();//GetRandomScalar();
		ry = CountUnitType(UNIT_TYPEID::TERRAN_BARRACKS) % 2 == 0 ? -GetRandomFraction() : GetRandomFraction();//GetRandomScalar();
		scaleX = GetRandomInteger(30, 45);//25.0f;
		scaleY = GetRandomInteger(40, 60);//35.0f;
	}

	if (ability_type_for_structure == ABILITY_ID::BUILD_REFINERY) {
		Units bases = observation->GetUnits(Unit::Alliance::Self, IsTownHall());
		
		/*Point2D start = *StartPosition;
		//Point2D start = bases[0]->pos;
		const Unit* gas_target = FindNearestGas(start);
		Actions()->UnitCommand(unit_to_build, ability_type_for_structure, gas_target);*/
		for (const auto& base : bases)
		{
			BuildAvailableGeaser(ABILITY_ID::BUILD_REFINERY, UNIT_TYPEID::TERRAN_SCV, base->pos);
		}
	}
	else {
		//if (ability_type_for_structure == ABILITY_ID::BUILD_BARRACKS) cout << "x : " << unit_to_build->pos.x + rx * 15.0f << " - y: " << unit_to_build->pos.y + ry * 15.0f << endl;
		Actions()->UnitCommand(unit_to_build,
			ability_type_for_structure,
			Point2D(unit_to_build->pos.x + rx * scaleX, unit_to_build->pos.y + ry * scaleY));
	}

	return true;
}

bool FANbot::TryBuildSupplyDepot() {
	const ObservationInterface* observation = Observation();

	// If we are not supply capped, don't build a supply depot.
	if (observation->GetFoodUsed() <= observation->GetFoodCap() - 2)
		return false;

	// Try and build a depot. Find a random SCV and give it the order.
	return TryBuildStructure(ABILITY_ID::BUILD_SUPPLYDEPOT);
}

size_t FANbot::CountUnitType(UNIT_TYPEID unit_type) {
	return Observation()->GetUnits(Unit::Alliance::Self, IsUnit(unit_type)).size();
}


bool FANbot::TryBuildBarracks() {
	const ObservationInterface* observation = Observation();
	if (CountUnitType(UNIT_TYPEID::TERRAN_SUPPLYDEPOT) < 1 || observation->GetMinerals() < 150) {
		return false;
	}
	return TryBuildStructure(ABILITY_ID::BUILD_BARRACKS);
}
bool FANbot::TryBuildRefinery() {
	const ObservationInterface* observation = Observation();
	if (CountUnitType(UNIT_TYPEID::TERRAN_REFINERY) >= 2 || observation->GetMinerals() < 75) {
		return false;
	}
	return TryBuildStructure(ABILITY_ID::BUILD_REFINERY);
}
bool FANbot::TryBuildFactory() {
	if (Observation()->GetMinerals() < 150 && Observation()->GetVespene() < 100) {
		return false;
	}
	return TryBuildStructure(ABILITY_ID::BUILD_FACTORY);
}

const Unit* FANbot::FindNearestMineralPatch(const Point2D& start) {
	Units units = Observation()->GetUnits(Unit::Alliance::Neutral);
	float distance = std::numeric_limits<float>::max();
	const Unit* target = nullptr;
	for (const auto& u : units) {
		if (u->unit_type == UNIT_TYPEID::NEUTRAL_MINERALFIELD) {
			float d = DistanceSquared2D(u->pos, start);
			if (d < distance) {
				distance = d;
				target = u;
			}
		}
	}
	return target;
}
const Unit* FANbot::FindNearestGas(const Point2D& start) {
	Units units = Observation()->GetUnits(Unit::Alliance::Neutral);
	float distance = std::numeric_limits<float>::max();
	const Unit* target = nullptr;
	for (const auto& u : units) {
		if (u->unit_type == UNIT_TYPEID::NEUTRAL_VESPENEGEYSER) {
			float d = DistanceSquared2D(u->pos, start);
			if (d < distance) {
				distance = d;
				target = u;
			}
		}
	}
	return target;
}

bool FANbot::BuildAvailableGeaser(AbilityID build_ability, UnitTypeID worker_type, Point2D base_location)
{
	const ObservationInterface* observation = Observation();
	Units geysers = observation->GetUnits(Unit::Alliance::Neutral, IsVespeneGeyser());

	//only search within this radius
	float minimum_distance = 15.0f;
	Tag closestGeyster = 0;
	for (const auto& geyser : geysers) {
		float current_distance = Distance2D(base_location, geyser->pos);
		if (current_distance < minimum_distance) {
			if (Query()->Placement(build_ability, geyser->pos)) {
				minimum_distance = current_distance;
				closestGeyster = geyser->tag;
			}
		}
	}

	// In the case where there are no more available geysers nearby
	if (closestGeyster == 0) {
		return false;
	}
	return TryBuildStructureByTag(build_ability, worker_type, closestGeyster);
}

//Try to build a structure based on tag, Used mostly for Vespene, since the pathing check will fail even though the geyser is "Pathable"
bool FANbot::TryBuildStructureByTag(AbilityID ability_type_for_structure, UnitTypeID unit_type, Tag location_tag) {
	const ObservationInterface* observation = Observation();
	Units workers = observation->GetUnits(Unit::Alliance::Self, IsUnit(unit_type));
	const Unit* target = observation->GetUnit(location_tag);

	if (workers.empty()) {
		return false;
	}

	// Check to see if there is already a worker heading out to build it
	for (const auto& worker : workers) {
		for (const auto& order : worker->orders) {
			if (order.ability_id == ability_type_for_structure) {
				return false;
			}
		}
	}

	// If no worker is already building one, get a random worker to build one
	srand(time(0));
	const Unit *unit = GetRandomEntry(workers);

	// Check to see if unit can build there
	if (Query()->Placement(ability_type_for_structure, target->pos)) {
		Actions()->UnitCommand(unit, ability_type_for_structure, target);
		return true;
	}
	return false;
}