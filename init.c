
void main()
{

	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	Weather weather = g_Game.GetWeather();

	weather.GetOvercast().SetLimits( 0.0 , 1.0 );
	weather.GetRain().SetLimits( 0.0 , 1.0 );
	weather.GetFog().SetLimits( 0.0 , 0.25 );

	weather.GetOvercast().SetForecastChangeLimits( 0.0, 0.2 );
	weather.GetRain().SetForecastChangeLimits( 0.0, 0.1 );
	weather.GetFog().SetForecastChangeLimits( 0.15, 0.45 );

	weather.GetOvercast().SetForecastTimeLimits( 1800 , 1800 );
	weather.GetRain().SetForecastTimeLimits( 600 , 600 );
	weather.GetFog().SetForecastTimeLimits( 1800 , 1800 );

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.0, 0.3), 0, 0);
	weather.GetRain().Set( Math.RandomFloatInclusive(0.0, 0.2), 0, 0);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.0, 0.1), 0, 0);
	
	weather.SetWindMaximumSpeed(15);
	weather.SetWindFunctionParams(0.1, 0.3, 50);
}

class CustomMission: MissionServer
{	
	void SetRandomHealth(EntityAI itemEnt)
	{
		int rndHlt = Math.RandomInt(40,100);
		itemEnt.SetHealth("","",rndHlt);
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		
		return m_player;
	}
	
	void addMags(PlayerBase player, string mag_type, int count)
	{
		if (count < 1)
				return;
			
			EntityAI mag;
			
			for (int i = 0; i < count; i++)
			{
				mag = player.GetInventory().CreateInInventory(mag_type);
				player.SetQuickBarEntityShortcut(mag, i + 1, true);
			}
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		player.RemoveAllItems();
		
		EntityAI itemEnt;
		ItemBase itemBs;
	
		switch (Math.RandomInt(0, 50)) {
		
			case 0: 
				itemEnt = player.GetInventory().CreateInInventory("PrisonUniformPants");
				itemEnt = player.GetInventory().CreateInInventory("PrisonUniformJacket");
				itemEnt = player.GetInventory().CreateInInventory("PrisonerCap");
				itemEnt = player.GetInventory().CreateInInventory("Sneakers_Gray");
			break;
			
			case 1: 
				itemEnt = player.GetInventory().CreateInInventory("TTSKOPants");
				itemEnt = player.GetInventory().CreateInInventory("TTsKOJacket_Camo");
				itemEnt = player.GetInventory().CreateInInventory("MilitaryBeret_CDF");
				itemEnt = player.GetInventory().CreateInInventory("MilitaryBoots_Black");
				
			break;
			
			case 2: 
				itemEnt = player.GetInventory().CreateInInventory("TrackSuitPants_Black");
				itemEnt = player.GetInventory().CreateInInventory("TrackSuitJacket_Black");
				itemEnt = player.GetInventory().CreateInInventory("JoggingShoes_Black");
				itemEnt = player.GetInventory().CreateInInventory("ThinFramesGlasses");
			break;
			
			case 3: 
				itemEnt = player.GetInventory().CreateInInventory("FirefightersPants_Beige");
				itemEnt = player.GetInventory().CreateInInventory("FirefighterJacket_Beige");
				itemEnt = player.GetInventory().CreateInInventory("FirefightersHelmet_Yellow");
				itemEnt = player.GetInventory().CreateInInventory("MilitaryBoots_Black");
			break;
			
			case 4: 
				itemEnt = player.GetInventory().CreateInInventory("GorkaPants_Autumn");
				itemEnt = player.GetInventory().CreateInInventory("GorkaEJacket_Autumn");
				itemEnt = player.GetInventory().CreateInInventory("MilitaryBoots_Black");
			break;
			
			case 5: 
				itemEnt = player.GetInventory().CreateInInventory("HunterPants_Spring");
				itemEnt = player.GetInventory().CreateInInventory("HuntingJacket_Spring");
				itemEnt = player.GetInventory().CreateInInventory("HikingBoots_Brown");
			break;
			
			case 6: 
				itemEnt = player.GetInventory().CreateInInventory("HunterPants_Summer");
				itemEnt = player.GetInventory().CreateInInventory("HuntingJacket_Summer");
				itemEnt = player.GetInventory().CreateInInventory("HikingBoots_Brown");
			break;
			
			case 7: 
				itemEnt = player.GetInventory().CreateInInventory("Jeans_Blue");
				itemEnt = player.GetInventory().CreateInInventory("Hoodie_Black");
				itemEnt = player.GetInventory().CreateInInventory("Sneakers_Red");
				itemEnt = player.GetInventory().CreateInInventory("RocketAviators");
			break;
			
			case 8: 
				itemEnt = player.GetInventory().CreateInInventory("SlacksPants_Black");
				itemEnt = player.GetInventory().CreateInInventory("TShirt_RedBlackStripes");
				itemEnt = player.GetInventory().CreateInInventory("MilitaryBoots_Black");
				itemEnt = player.GetInventory().CreateInInventory("CowboyHat_black");
			break;
			
			case 9: 
				itemEnt = player.GetInventory().CreateInInventory("SlacksPants_White");
				itemEnt = player.GetInventory().CreateInInventory("LabCoat");
				itemEnt = player.GetInventory().CreateInInventory("JoggingShoes_White");
				itemEnt = player.GetInventory().CreateInInventory("NioshFaceMask");
			break;
			
			case 10: 
				itemEnt = player.GetInventory().CreateInInventory("USMCPants_Woodland");
				itemEnt = player.GetInventory().CreateInInventory("USMCJacket_Woodland");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Beige");
			break;
			
			case 11: 
				itemEnt = player.GetInventory().CreateInInventory("USMCPants_Desert");
				itemEnt = player.GetInventory().CreateInInventory("USMCJacket_Desert");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Beige");
			break;
			
			case 12: 
				itemEnt = player.GetInventory().CreateInInventory("Breeches_Blue");
				itemEnt = player.GetInventory().CreateInInventory("Raincoat_Yellow");
				itemEnt = player.GetInventory().CreateInInventory("Wellies_Black");
			break;
			
			case 13: 
				itemEnt = player.GetInventory().CreateInInventory("NBCPantsGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCJacketGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCBootsGray");
				itemEnt = player.GetInventory().CreateInInventory("NBCGlovesGray");
				itemEnt = player.GetInventory().CreateInInventory("GasMask");
			break;
			
			case 14: 
				itemEnt = player.GetInventory().CreateInInventory("SlacksPants_Black");
				itemEnt = player.GetInventory().CreateInInventory("WoolCoat_Beige");
				itemEnt = player.GetInventory().CreateInInventory("MilitaryBoots_Brown");
			break;
			
			case 15: 
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
				itemEnt = player.GetInventory().CreateInInventory("M65Jacket_Black");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
			break;

			case 16: 
				itemEnt = player.GetInventory().CreateInInventory("Sword");
				itemEnt = player.GetInventory().CreateInInventory("GreatHelm");
			break;
			
			case 17: 
				itemEnt = player.GetInventory().CreateInInventory("Jeans_Blue");
				itemEnt = player.GetInventory().CreateInInventory("BomberJacket_Brown");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Beige");
			break;

			case 18: 
				itemEnt = player.GetInventory().CreateInInventory("MedicalScrubsPants_Blue");
				itemEnt = player.GetInventory().CreateInInventory("MedicalScrubsShirt_Blue");
				itemEnt = player.GetInventory().CreateInInventory("JoggingShoes_Blue");
				itemEnt = player.GetInventory().CreateInInventory("NioshFaceMask");
			break;

			case 19: 
				itemEnt = player.GetInventory().CreateInInventory("MedicalScrubsPants_White");
				itemEnt = player.GetInventory().CreateInInventory("MedicalScrubsShirt_White");
				itemEnt = player.GetInventory().CreateInInventory("JoggingShoes_White");
				itemEnt = player.GetInventory().CreateInInventory("NioshFaceMask");
			break;
			
			case 20: 
				itemEnt = player.GetInventory().CreateInInventory("GorkaPants_Flat");
				itemEnt = player.GetInventory().CreateInInventory("GorkaEJacket_Flat");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
				itemEnt = player.GetInventory().CreateInInventory("MilitaryBeret_Red");
			break;

			case 21: 
				itemEnt = player.GetInventory().CreateInInventory("Jeans_Blue");
				itemEnt = player.GetInventory().CreateInInventory("BomberJacket_Brown");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Brown");
				itemEnt = player.GetInventory().CreateInInventory("CowboyHat_Brown");
			break;

			case 22: 
				itemEnt = player.GetInventory().CreateInInventory("TrackSuitPants_Red");
				itemEnt = player.GetInventory().CreateInInventory("HikingJacket_Red");
				itemEnt = player.GetInventory().CreateInInventory("Sneakers_Red");
				itemEnt = player.GetInventory().CreateInInventory("Bandana_Redpattern");
				itemEnt = player.GetInventory().CreateInInventory("DallasMask");
			break;

			case 23: 
				itemEnt = player.GetInventory().CreateInInventory("TrackSuitPants_Red");
				itemEnt = player.GetInventory().CreateInInventory("HikingJacket_Red");
				itemEnt = player.GetInventory().CreateInInventory("Sneakers_Red");
				itemEnt = player.GetInventory().CreateInInventory("Bandana_Redpattern");
				itemEnt = player.GetInventory().CreateInInventory("HoxtonMask");
			break;

			case 24: 
				itemEnt = player.GetInventory().CreateInInventory("TrackSuitPants_Red");
				itemEnt = player.GetInventory().CreateInInventory("HikingJacket_Red");
				itemEnt = player.GetInventory().CreateInInventory("Sneakers_Red");
				itemEnt = player.GetInventory().CreateInInventory("Bandana_Redpattern");
				itemEnt = player.GetInventory().CreateInInventory("WolfMask");
			break;

			case 25: 
				itemEnt = player.GetInventory().CreateInInventory("NurseDress_Blue");
				itemEnt = player.GetInventory().CreateInInventory("JoggingShoes_Violet");
				itemEnt = player.GetInventory().CreateInInventory("Bandana_Polkapattern");
				itemEnt = player.GetInventory().CreateInInventory("NioshFaceMask");
			break;

			case 26: 
				itemEnt = player.GetInventory().CreateInInventory("PolicePants");
				itemEnt = player.GetInventory().CreateInInventory("PoliceJacket");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
				itemEnt = player.GetInventory().CreateInInventory("OfficerHat");
			break;

			case 27: 
				itemEnt = player.GetInventory().CreateInInventory("Jeans_Blue");
				itemEnt = player.GetInventory().CreateInInventory("QuiltedJacket_Blue");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Brown");
				itemEnt = player.GetInventory().CreateInInventory("BeanieHat_Grey");
			break;

			case 28: 
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
				itemEnt = player.GetInventory().CreateInInventory("RidersJacket_Black");
				itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Black");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
				itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Black");
				itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Black");
				itemEnt = player.GetInventory().CreateInInventory("TankerHelmet");
			break;
			
			case 29: 
				itemEnt = player.GetInventory().CreateInInventory("ParamedicPants_Crimson");
				itemEnt = player.GetInventory().CreateInInventory("ParamedicJacket_Crimson");
				itemEnt = player.GetInventory().CreateInInventory("JoggingShoes_Red");
			break;
			
			case 30: 
				itemEnt = player.GetInventory().CreateInInventory("PolicePants");
				itemEnt = player.GetInventory().CreateInInventory("PoliceJacket");
				itemEnt = player.GetInventory().CreateInInventory("PoliceVest");
				itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Black");
				itemEnt = player.GetInventory().CreateInInventory("MilitaryBoots_Black");
				itemEnt = player.GetInventory().CreateInInventory("DirtBikeHelmet_Police");
				itemEnt = player.GetInventory().CreateInInventory("AviatorGlasses");
			break;
			
			case 31: 
				itemEnt = player.GetInventory().CreateInInventory("Breeches_Green");
				itemEnt = player.GetInventory().CreateInInventory("TShirt_White");
				itemEnt = player.GetInventory().CreateInInventory("Sneakers_Red");
				itemEnt = player.GetInventory().CreateInInventory("DirtBikeHelmet_Chernarus");
				itemEnt = player.GetInventory().CreateInInventory("AviatorGlasses");
			break;
			
			case 32: 
				itemEnt = player.GetInventory().CreateInInventory("TTSKOPants");
				itemEnt = player.GetInventory().CreateInInventory("TTsKOJacket_Camo");
				itemEnt = player.GetInventory().CreateInInventory("WorkingBoots_Beige");
				itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Beige");
				itemEnt = player.GetInventory().CreateInInventory("BoonieHat_Tan");
			break;
			
			case 33: 
				itemEnt = player.GetInventory().CreateInInventory("BDUPants");
				itemEnt = player.GetInventory().CreateInInventory("TShirt_Beige");
				itemEnt = player.GetInventory().CreateInInventory("MilitaryBoots_Black");
				itemEnt = player.GetInventory().CreateInInventory("BandanaUntieable_RedPattern");
			break;
			
			case 34: 
				itemEnt = player.GetInventory().CreateInInventory("TTSKOPants");
				itemEnt = player.GetInventory().CreateInInventory("TTsKOJacket_Camo");
				itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Olive");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Green");
				itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Green");
				itemEnt = player.GetInventory().CreateInInventory("BallisticHelmet_Green");
			break;
			
			case 35: 
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Beige");
				itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Tan");
				itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Olive");
				itemEnt = player.GetInventory().CreateInInventory("WorkingBoots_Beige");
				itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Beige");
				itemEnt = player.GetInventory().CreateInInventory("BallisticHelmet_Green");
			break;
			
			case 36: 
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Green");
				itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Olive");
				itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Olive");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
				itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Green");
				itemEnt = player.GetInventory().CreateInInventory("BallisticHelmet_Green");
			break;
			
			case 37: 
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
				itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Black");
				itemEnt = player.GetInventory().CreateInInventory("UKAssVest_Black");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
				itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Black");
				itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Blackskull");
				itemEnt = player.GetInventory().CreateInInventory("BallisticHelmet_Black");
			break;
			
			case 38: 
				itemEnt = player.GetInventory().CreateInInventory("GorkaPants_Summer");
				itemEnt = player.GetInventory().CreateInInventory("GorkaEJacket_Summer");
				itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Olive");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Beige");
				itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Beige");
				itemEnt = player.GetInventory().CreateInInventory("BallisticHelmet_Green");
			break;
			
			case 39: 
				itemEnt = player.GetInventory().CreateInInventory("USMCPants_Woodland");
				itemEnt = player.GetInventory().CreateInInventory("USMCJacket_Woodland");
				itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Olive");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Beige");
				itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Beige");
				itemEnt = player.GetInventory().CreateInInventory("BallisticHelmet_Green");
			break;
			
			case 40: 
				itemEnt = player.GetInventory().CreateInInventory("GhillieSuit_Woodland");
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Green");
				itemEnt = player.GetInventory().CreateInInventory("M65Jacket_Olive");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Green");
				itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Green");
				itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Green");
				itemEnt = player.GetInventory().CreateInInventory("GhillieHood_Woodland");
			break;
			
			case 41: 
				itemEnt = player.GetInventory().CreateInInventory("GhillieSuit_Mossy");
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Green");
				itemEnt = player.GetInventory().CreateInInventory("M65Jacket_Olive");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Green");
				itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Green");
				itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Green");
				itemEnt = player.GetInventory().CreateInInventory("GhillieHood_Mossy");
			break;
			
			case 42: 
				itemEnt = player.GetInventory().CreateInInventory("GhillieSuit_Tan");
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Beige");
				itemEnt = player.GetInventory().CreateInInventory("M65Jacket_Tan");
				itemEnt = player.GetInventory().CreateInInventory("WorkingBoots_Beige");
				itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Beige");
				itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Beige");
				itemEnt = player.GetInventory().CreateInInventory("GhillieHood_Tan");
			break;
			
			case 43: 
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
				itemEnt = player.GetInventory().CreateInInventory("M65Jacket_Black");
				itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Black");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
				itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Black");
				itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Black");
				itemEnt = player.GetInventory().CreateInInventory("GorkaHelmetComplete_Black");
			break;
			
			case 44: 
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Green");
				itemEnt = player.GetInventory().CreateInInventory("M65Jacket_Olive");
				itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Olive");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Green");
				itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Green");
				itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Green");
				itemEnt = player.GetInventory().CreateInInventory("GorkaHelmetComplete_Green");
			break;
			
			case 45: 
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
				itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Black");
				itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Black");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
				itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Black");
				itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Black");
				itemEnt = player.GetInventory().CreateInInventory("DarkMotoHelmet_Black");
			break;
			
			case 46: 
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Green");
				itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Olive");
				itemEnt = player.GetInventory().CreateInInventory("HighCapacityVest_Olive");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Green");
				itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Green");
				itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Green");
				itemEnt = player.GetInventory().CreateInInventory("DarkMotoHelmet_Green");
			break;
			
			case 47: 
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Green");
				itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Tan");
				itemEnt = player.GetInventory().CreateInInventory("UKAssVest_Olive");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
				itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Black");
				itemEnt = player.GetInventory().CreateInInventory("BaseballCap_Black");
			break;
			
			case 48: 
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Beige");
				itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Tan");
				itemEnt = player.GetInventory().CreateInInventory("AssaultBag_Green");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Beige");
				itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Beige");
				itemEnt = player.GetInventory().CreateInInventory("BoonieHat_Tan");
			break;
			
			case 49: 
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
				itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Black");
				itemEnt = player.GetInventory().CreateInInventory("AssaultBag_Black");
				itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
				itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Black");
				itemEnt = player.GetInventory().CreateInInventory("BoonieHat_Black");
			break;
			
		}
				
		itemEnt = player.GetInventory().CreateInInventory("SodaCan_Pipsi");
		itemEnt = player.GetInventory().CreateInInventory("TunaCan");
		itemEnt = player.GetInventory().CreateInInventory("Ammo_380");
		itemEnt = player.GetInventory().CreateInInventory("MakarovIJ70");player.SetQuickBarEntityShortcut(itemEnt, 0);
		addMags(player, "Mag_IJ70_8Rnd", 1);
		itemBs = ItemBase.Cast(itemEnt);

	}
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
