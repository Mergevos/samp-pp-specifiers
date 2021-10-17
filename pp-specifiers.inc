#include <a_samp>
#include <PawnPlus>

#if !defined strcmp_s
    native strcmp_s(ConstAmxString: string1, const string2[], bool:ignorecase=false, lenght=cellmax) = strcmp;
#endif 

static stock vehNames[][] =
{
	"Landstalker","Bravura","Buffalo","Linerunner","Perrenial","Sentinel",
	"Dumper","Firetruck","Trashmaster","Stretch","Manana","Infernus",
	"Voodoo","Pony","Mule","Cheetah","Ambulance","Leviathan","Moonbeam",
	"Esperanto","Taxi","Washington","Bobcat","Whoopee","BF Injection",
	"Hunter","Premier","Enforcer","Securicar","Banshee","Predator","Bus",
	"Rhino","Barracks","Hotknife","Trailer","Previon","Coach","Cabbie",
	"Stallion","Rumpo","RC Bandit","Romero","Packer","Monster","Admiral",
	"Squalo","Seasparrow","Pizzaboy","Tram","Trailer","Turismo","Speeder",
	"Reefer","Tropic","Flatbed","Yankee","Caddy","Solair","Berkley's RC Van",
	"Skimmer","PCJ-600","Faggio","Freeway","RC Baron","RC Raider","Glendale",
	"Oceanic","Sanchez","Sparrow","Patriot","Quad","Coastguard","Dinghy",
	"Hermes","Sabre","Rustler","ZR-350","Walton","Regina","Comet","BMX",
	"Burrito","Camper","Marquis","Baggage","Dozer","Maverick","News Chopper",
	"Rancher","FBI Rancher","Virgo","Greenwood","Jetmax","Hotring","Sandking",
	"Blista Compact","Police Maverick","Boxvillde","Benson","Mesa","RC Goblin",
	"Hotring Racer A","Hotring Racer B","Bloodring Banger","Rancher","Super GT",
	"Elegant","Journey","Bike","Mountain Bike","Beagle","Cropduster","Stunt",
	"Tanker","Roadtrain","Nebula","Majestic","Buccaneer","Shamal","Hydra",
	"FCR-900","NRG-500","HPV1000","Cement Truck","Tow Truck","Fortune",
	"Cadrona","FBI Truck","Willard","Forklift","Tractor","Combine","Feltzer",
	"Remington","Slamvan","Blade","Freight","Streak","Vortex","Vincent",
	"Bullet","Clover","Sadler","Firetruck","Hustler","Intruder","Primo",
	"Cargobob","Tampa","Sunrise","Merit","Utility","Nevada","Yosemite",
	"Windsor","Monster","Monster","Uranus","Jester","Sultan","Stratum",
	"Elegy","Blackhawk","RC Tiger","Flash","Tahoma","Savanna","Bandito",
	"Freight Flat","Streak Carriage","Kart","Mower","Dune","Sweeper",
	"Broadway","Tornado","AT-400","DFT-30","Huntley","Stafford","BF-400",
	"News Van","Tug","Trailer","Emperor","Wayfarer","Euros","Hotdog","Club",
	"Freight Box","Trailer","Andromada","Dodo","RC Cam","Launch","Police Car",
	"Police Car","Police Car","Police Ranger","Picador","S.W.A.T","Alpha",
	"Phoenix","Glendale","Sadler","Luggage","Luggage","Stairs","Boxville",
	"Tiller","Utility Trailer"
};

/**
 * <summary> %w specifier </summary>
 * <param name="weaponid"> ID of weapon.</param>
 * <returns> Weapon name if weapon is valid, otherwise NULL string. </returns>
 * <remarks> 
    This function takes weaponid and checks if weapon is valid. If the conditional statement is true,
    it returns weapon name, otherwise NULL string.
   </remarks>
 */

forward String:__ppspec_weaponspecifier(weaponid);
public String:__ppspec_weaponspecifier(weaponid)
{
    new weapon[40];
    if(weaponid < 0 || weaponid > 35) 
    {
        return STRING_NULL;
    }
    GetWeaponName(weaponid, weapon, sizeof(weapon));
    return str_new(weapon);
}

/**
 * <summary> %r specifier </summary>
 * <param name="playerid"> ID of player.</param>
 * <returns> Player name if player is connected, otherwise NULL string. </returns>
 * <remarks> 
    This function takes playerid and checks if player is connected. If the conditional statement is true,
    it returns player name, otherwise NULL string.
   </remarks>
 */

forward String:__ppspec_playernamespecifier(playerid);
public String:__ppspec_playernamespecifier(playerid)
{
    new name[MAX_PLAYER_NAME];
    if(!IsPlayerConnected(playerid)) 
    {
        return STRING_NULL;
    }
    GetPlayerName(playerid, name, sizeof(name));
    return str_new(name);
}

/**
 * <summary> %W specifier </summary>
 * <param name="weaponid"> ID of weapon.</param>
 * <returns> Weapon name if weapon is valid, otherwise NULL string. </returns>
 * <remarks> 
    This function takes weaponid and checks if weapon is valid. If the conditional statement is true,
    it returns weapon name in lowercase, used in sentences, otherwise NULL string.
   </remarks>
 */

forward String:__ppspec_weaponspecifiersent(weaponid);
public String:__ppspec_weaponspecifiersent(weaponid)
{
    new weapon[40];
    if(weaponid < 0 || weaponid > 35) 
    {
        return STRING_NULL;
    }
    GetWeaponName(weaponid, weapon, sizeof(weapon)); 
    return str_to_lower(str_new(weapon));
}

/**
 * <summary> %m specifier </summary>
 * <param name="modelid"> Name of model.</param>
 * <returns> Model name if modelid is valid, otherwise NULL string. </returns>
 * <remarks> 
    This function takes modelid and checks if model is valid. If the conditional statement is true,
    it returns model name, otherwise NULL string.
   </remarks>
 */

forward String:__ppspec_modelvehname(modelid);
public String:__ppspec_modelvehname(modelid)
{
    if(modelid < 400 || modelid > 611)
    {
        return STRING_NULL;
    }
    return str_format("%s", vehNames[modelid - 400]);
}

/**
 * <summary> %M specifier </summary>
 * <param name="modelid"> Name of model.</param>
 * <returns> Model name if modelid is valid, otherwise NULL string. </returns>
 * <remarks> 
    This function takes modelid and checks if model is valid. If the conditional statement is true,
    it returns model name in lowercase, used in sentences, otherwise model string.
   </remarks>
 */

forward String:__ppspec_modelvehnamesent(modelid);
public String:__ppspec_modelvehnamesent(modelid)
{
    if(modelid < 400 || modelid > 611)
    {
        return STRING_NULL;
    }
    
    return str_to_lower(str_format("%s", vehNames[modelid - 400]));
}

/**
 * <summary> %a specifier </summary>
 * <param name="vehicleid"> ID of vehicle.</param>
 * <returns> Model ID if vehicleid is valid, otherwise NULL string. </returns>
 * <remarks> 
    This function takes vehicleid and checks if vehicleid is valid. If the conditional statement is true,
    it returns modelid, otherwise NULL string.
   </remarks>
 */

forward String:__ppspec_modelfromvehicle(vehicleid);
public String:__ppspec_modelfromvehicle(vehicleid)
{
    if(!IsValidVehicle(vehicleid))
    {
        return STRING_NULL;
    }
    return str_format("%d", GetVehicleModel(vehicleid));
}

/**
 * <summary> %l specifier </summary>
 * <param name="name"> Name of model.</param>
 * <returns> Modelid if model name is valid, otherwise NULL string. </returns>
 * <remarks> 
    This function takes model name and checks if model name is valid. If the conditional statement is true,
    it returns model id, otherwise NULL string.
   </remarks>
 */

forward String: __ppspec_modelidnamesent(String: name);
public String: __ppspec_modelidnamesent(String: name)
{
    for(new i; i < sizeof(vehNames); i++)
    {
        if(!strcmp_s(name, vehNames[i], true))
        {
            return str_format("%d", i+400);
        }
    }
    return STRING_NULL;
}

// --
// Init and final
// --

forward _pp@on_init@ppspec();
public _pp@on_init@ppspec()
{
    
    printf("[PP Specifiers] Loaded. Version %s by Mergevos", "1.0.0");

    PP_RegisterSpecifier('w', "__ppspec_weaponspecifier", false);
    PP_RegisterSpecifier('W', "__ppspec_weaponspecifiersent", false);
    PP_RegisterSpecifier('r', "__ppspec_playernamespecifier", false);
    PP_RegisterSpecifier('M', "__ppspec_modelvehnamesent", false);
    PP_RegisterSpecifier('m', "__ppspec_modelvehname", false);
    PP_RegisterSpecifier('l', "__ppspec_modelidnamesent", false);
    PP_RegisterSpecifier('a', "__ppspec_modelfromvehicle", false);
    
}

forward _pp@on_exit@ppspec();
public _pp@on_exit@ppspec()
{
    printf("[PP Specifiers] Unoaded. Version %s by Mergevos", "1.0.0");
}

// --

stock PP_RegisterSpecifier(specifier, const handler[], bool:is_string=false)
{
    new name[] = "._tag";
    name[0] = specifier;
    new tag_uid:uid = tag_new(name);
    tag_set_op(uid, tag_op_format, handler);
    tag_lock(uid);
    return str_register_format(specifier, uid, is_string);
}

