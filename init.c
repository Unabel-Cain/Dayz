
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
		int rndHlt = Math.RandomInt(100,100);
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
	
	override void OnInit()
	{

		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(NumPLayersOnServer, 180000, true);		// 3 Minutes
	}
	
	void NumPLayersOnServer()
	
	{
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		int numPlayers = players.Count();
		
		for ( int i = 0; i < players.Count(); ++i )
		{
			Man player = players.Get(i);
			if( player )
			{
				string messPlayers = numPlayers.ToString() + " Players Online";
				Param1<string> m_MessageParam = new Param1<string>(messPlayers); 
				GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_MessageParam, true, player.GetIdentity()); 

			}
		}
		
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		TStringArray head = {"BoonieHat_Black","BoonieHat_Blue","BoonieHat_DPM","BoonieHat_Dubok","BoonieHat_Flecktran","BoonieHat_NavyBlue","BoonieHat_Olive","BoonieHat_Orange","BoonieHat_Red","BoonieHat_Tan","CowboyHat_black","CowboyHat_Brown","CowboyHat_darkBrown","CowboyHat_green","PilotkaCap","PrisonerCap","ConstructionHelmet_Blue","ConstructionHelmet_Lime","ConstructionHelmet_Orange","ConstructionHelmet_Red","ConstructionHelmet_White","ConstructionHelmet_Yellow","LeatherHat_Black","ZSh3PilotHelmet_Green","MotoHelmet_Black","MotoHelmet_Blue","MotoHelmet_Green","MotoHelmet_Grey","MotoHelmet_Lime","MotoHelmet_Red","MotoHelmet_White"};
		TStringArray face = {"AviatorGlasses","JoeyXSunGlasses","RocketAviators","ThickGramesGlasses","ThinFramesGlasses"};
		TStringArray tops = {"Hoodie_Blue","Hoodie_Black","Hoodie_Brown","Hoodie_Green","Hoodie_Grey","Hoodie_Red","TShirt_Beige","TShirt_Black","TShirt_Blue","TShirt_Green","TShirt_Grey","TShirt_OrangeWhiteStripes","TShirt_Red","TShirt_RedBlackStripes","TShirt_White","PrisonUniformJacket","BomberJacket_Black","BomberJacket_Blue","BomberJacket_Brown","BomberJacket_Grey","BomberJacket_Maroon","BomberJacket_Olive","BomberJacket_SkyBlue","HikingJacket_Black","HikingJacket_Blue","HikingJacket_Red","HikingJacket_Green","HuntingJacket_Autumn","HuntingJacket_Brown","HuntingJacket_Spring","HuntingJacket_Summer","HuntingJacket_Winter","RidersJacket_Black"};
		TStringArray pants = {"Breeches_Pink","Breeches_White","PrisonUniformPants","Jeans_Black","Jeans_BlueDark","Jeans_Blue","Jeans_Brown","Jeans_Green","Jeans_Grey","CanvasPants_Beige","CanvasPants_Blue","CanvasPants_Grey","CanvasPants_Red","CanvasPants_Violet","CargoPants_Beige","CargoPants_Black","CargoPants_Blue","CargoPants_Green","CargoPants_Grey","HunterPants_Brown","HunterPants_Autumn","HunterPants_Spring","HunterPants_Summer","HunterPants_Winter"};
		TStringArray shoes = {"Ballerinas_Blue","Ballerinas_White","AthleticShoes_Black","AthleticShoes_Blue","AthleticShoes_Brown","AthleticShoes_Green","AthleticShoes_Grey","HikingBootsLow_Beige","HikingBootsLow_Black","HikingBootsLow_Blue","HikingBootsLow_Grey","HikingBoots_Black","HikingBoots_Brown","JoggingShoes_Black","JoggingShoes_Blue","JoggingShoes_Red","JoggingShoes_Violet","JoggingShoes_White"};
		TStringArray backpack = {"AliceBag_Black","AliceBag_Camo","AliceBag_Green","AssaultBag_Black","AssaultBag_Green","AssaultBag_Ttsko","CoyoteBag_Brown","CoyoteBag_Green","HuntingBag","MountainBag_Blue","MountainBag_Green","MountainBag_Orange","MountainBag_Red"};
		TStringArray food = {"SardinesCan","PeachesCan","Pear","Plum","Apple","TunaCan","AgaricusMushroom","AmanitaMushroom", "BoletusMushroom","LactariusMushroom","MacrolepiotaMushroom","PleurotusMushroom","PsilocybeMushroom"};
		TStringArray drink = {"SodaCan_Cola","SodaCan_Pipsi","SodaCan_Spite"};
		TStringArray water = {"WaterBottle","Canteen"};
		TStringArray gloves = {"NBCGlovesGray","WorkingGloves_Yellow"};
		TStringArray sidearm = {"Colt1911","CZ61","CZ75","Derringer_Black","Derringer_Grey","Derringer_Pink","FNX45","Glock19","MarkarovPB","P1"};
		
		player.RemoveAllItems();
		
		EntityAI itemEnt;
		EntityAI itemIn;
		ItemBase itemBs;
		int rndQnt;
		
		EntityAI item1 = player.GetInventory().CreateInInventory(backpack.GetRandomElement());
		EntityAI item2 = player.GetInventory().CreateInInventory(tops.GetRandomElement());
		EntityAI item3 = player.GetInventory().CreateInInventory(shoes.GetRandomElement());
		EntityAI item4 = player.GetInventory().CreateInInventory(pants.GetRandomElement());
		EntityAI item5 = player.GetInventory().CreateInInventory(head.GetRandomElement());
		EntityAI item6 = player.GetInventory().CreateInInventory(face.GetRandomElement());
		EntityAI item7 = player.GetInventory().CreateInInventory(food.GetRandomElement());
		EntityAI item8 = player.GetInventory().CreateInInventory(drink.GetRandomElement());
		EntityAI item9 = player.GetInventory().CreateInInventory(water.GetRandomElement());
		EntityAI item10 = player.GetInventory().CreateInInventory(gloves.GetRandomElement());
		EntityAI item11 = player.GetInventory().CreateInInventory(sidearm.GetRandomElement());
		
		itemEnt = player.GetInventory().CreateInInventory("AKM");
		itemBs = ItemBase.Cast(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 2);
		
		itemIn = itemEnt.GetInventory().CreateAttachment("AK74U_Bttstck_Green");
		itemBs = ItemBase.Cast(itemIn);
		
		itemIn = itemEnt.GetInventory().CreateAttachment("AK74_Hndgrd_Camo");
		itemBs = ItemBase.Cast(itemIn);
		
		itemIn = itemEnt.GetInventory().CreateAttachment("AK_Suppressor");
		itemBs = ItemBase.Cast(itemIn);
		
		itemIn = itemEnt.GetInventory().CreateAttachment("ACOGOptic");
		itemBs = ItemBase.Cast(itemIn);
		
		itemEnt = player.GetInventory().CreateInInventory("BandageDressing");
		itemBs = ItemBase.Cast(itemEnt);

		itemEnt = player.GetInventory().CreateInInventory("Binoculars");
		itemBs = ItemBase.Cast(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 3);

		itemEnt = player.GetInventory().CreateInInventory("HuntingKnife");
		itemBs = ItemBase.Cast(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 0);

		/*itemEnt = player.GetInventory().CreateInInventory("M4A1");
		SetRandomHealth(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 1);
		
		itemIn = itemEnt.GetInventory().CreateAttachment("M4_T3NRDSOptic");
		SetRandomHealth(itemIn);
		
		itemIn = itemEnt.GetInventory().CreateAttachment("M4_OEBttstck");
		SetRandomHealth(itemIn);
		
		itemIn = itemEnt.GetInventory().CreateAttachment("M4_PlasticHndgrd");
		SetRandomHealth(itemIn);
		
		itemIn = itemEnt.GetInventory().CreateAttachment("M4_Suppressor");
		SetRandomHealth(itemIn);*/
		
		itemEnt = player.GetInventory().CreateInInventory("Mag_AKM_Drum75Rnd_Green");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("Mag_AKM_Drum75Rnd_Green");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("Mag_AKM_Drum75Rnd_Green");
		itemBs = ItemBase.Cast(itemEnt);
		itemBs.SetQuantity(4);
		
		/*itemEnt = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
		SetRandomHealth(itemEnt);
	
		itemEnt = player.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd");
		SetRandomHealth(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd");
		SetRandomHealth(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd");
		SetRandomHealth(itemEnt);*/
		
		/*itemEnt = player.GetInventory().CreateInInventory("FNX45");
		SetRandomHealth(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 2);

		itemIn = itemEnt.GetInventory().CreateAttachment("PistolSuppressor");
		SetRandomHealth(itemIn);
		
		itemEnt = player.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
		SetRandomHealth(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");
		SetRandomHealth(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");
		SetRandomHealth(itemEnt);	*/	
	}
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}