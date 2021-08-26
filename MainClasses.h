// Minecraft Dungeons Modding API
// Contributors:
// - Fx Morin (PR0CESS)

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/ActorComponent.h"
#include "Internationalization/Text.h"
#include "Engine/GameInstance.h"
#include "Engine/DataAsset.h"
#include "Engine/AssetManagerTypes.h"
#include "GameFramework/Info.h"
#include "Camera/CameraActor.h"
#include "GameFramework/Character.h"
//#include "GameplayPrediction.h"
#include "GameFramework/PlayerController.h"
#include "Basic.h"
#include "MainClasses.generated.h"

/*
UCLASS()
class DUNGEONS_API UMainClasses : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

};
*/

//---------------------------------------------------------------------------
// Enums
//---------------------------------------------------------------------------

UENUM(BlueprintType) // Enum Dungeons.EEnchantmentSource
enum class EEnchantmentSource : uint8
{
	Unset = 0,
	Permanent = 1,
	Generated = 2,
	Netherite = 3,
	Dust = 4
};


UENUM(BlueprintType) // Enum Dungeons.EEnchantmentCategory
enum class EEnchantmentCategory : uint8
{
	Unset = 0,
	Melee = 1,
	Ranged = 2,
	Aoe = 3,
	Armor = 4,
	Permanent = 5
};

UENUM(BlueprintType) // Enum Dungeons.EEnchantmentTypeID
enum class EEnchantmentTypeID : uint8
{
	Unset = 0,
	Sharpness = 1,
	Knockback = 2,
	Looting = 3,
	Prospector = 4,
	FireAspect = 5,
	Rampaging = 6,
	Exploding = 7,
	CriticalHit = 8,
	Freezing = 9,
	PoisonedMelee = 10,
	JunglePoisonMelee = 11,
	Leeching = 12,
	Aiding = 13,
	GravityMelee = 14,
	EnigmaResonatorMelee = 15,
	AnimaConduitMelee = 16,
	Stunning = 17,
	CaveSpiderPoisonEnchantment = 18,
	Swirling = 19,
	Smiting = 20,
	Committed = 21,
	SoulSiphon = 22,
	RadianceMelee = 23,
	Chains = 24,
	Thundering = 25,
	Echo = 26,
	Shockwave = 27,
	Weakening = 28,
	BusyBee = 29,
	DynamoMelee = 30,
	BaneOfIllagers = 31,
	Rushdown = 32,
	DamageSynergy = 33,
	PainCycle = 34,
	WitherEnchantmentMelee = 35,
	TempoTheft = 36,
	AlacrityAdjustment = 37,
	BowsBoon = 38,
	Ricochet = 39,
	Power = 40,
	Punch = 41,
	Infinity = 42,
	MultiShot = 43,
	Piercing = 44,
	ChainReaction = 45,
	Gravity = 46,
	HuntingBowEnchantment = 47,
	EnigmaResonatorRanged = 48,
	AnimaConduitRanged = 49,
	PoisonedRanged = 50,
	JunglePoisonRanged = 51,
	FreezingRanged = 52,
	RapidFire = 53,
	Supercharge = 54,
	BonusShot = 55,
	Unchanting = 56,
	FuseShot = 57,
	RadianceRanged = 58,
	Accelerating = 59,
	Growing = 60,
	WildRage = 61,
	SlowBowEnchantment = 62,
	DynamoRanged = 63,
	BurstBowstring = 64,
	ChargingAcceleration = 65,
	CogCrossbowEnchantment = 66,
	WindBowEnchantment = 67,
	CooldownShot = 68,
	ArtifactCharge = 69,
	WitherEnchantmentRanged = 70,
	ShockWeb = 71,
	FreezingAoe = 72,
	Protection = 73,
	Celerity = 74,
	FinalShout = 75,
	Deflecting = 76,
	Regeneration = 77,
	Thorns = 78,
	Altruistic = 79,
	Shielding = 80,
	Barrier = 81,
	HuntingBowTaggedEnchantment = 82,
	Recycler = 83,
	Chilling = 84,
	Cowardice = 85,
	Electrified = 86,
	Burning = 87,
	Snowing = 88,
	GravityPulse = 89,
	FireTrail = 90,
	Frenzied = 91,
	Swiftfooted = 92,
	SpiritSpeed = 93,
	PotionFortification = 94,
	FoodReserves = 95,
	SurpriseGift = 96,
	DoubleDamage = 97,
	FastAttack = 98,
	Quick = 99,
	HealthSynergy = 100,
	SpeedSynergy = 101,
	Explorer = 102,
	VesselTrail = 103,
	SlowResistance = 104,
	SlowImmunity = 105,
	TumbleBee = 106,
	BagOfSouls = 107,
	Acrobat = 108,
	PushVolumeImmunity = 109,
	WindResistance = 110,
	WindImmunity = 111,
	RollCharge = 112,
	MultiDodge = 113,
	EmeraldDivination = 114,
	DeathBarter = 115,
	ResurrectionSurge = 116,
	Huge = 117,
	ResurrectSurroundingMobs = 118,
	Invisible = 119,
	PoisonFocus = 120,
	FireFocus = 121,
	SoulFocus = 122,
	LightningFocus = 123,
	BeastSurge = 124,
	BeastBurst = 125,
	BeastBoss = 126,
	Reckless = 127,
	Last = 128
};

UENUM(BlueprintType) // Enum Dungeons.EItemRarity
enum class EItemRarity : uint8
{
	Common = 0,
	Rare = 1,
	Unique = 2
};

UENUM(BlueprintType) // Enum Dungeons.EArmorPropertyID
enum class EArmorPropertyID : uint8
{
	Unset = 0,
	SoulGatheringBoost = 1,
	SuperbDamageAbsorption = 2,
	MissChance = 3,
	TeleportChance = 4,
	ItemDamageBoost = 5,
	ItemCooldownDecrease = 6,
	AllyDamageBoost = 7,
	IncreasedArrowBundleSize = 8,
	MeleeDamageBoost = 9,
	MeleeAttackSpeedBoost = 10,
	RangedDamageBoost = 11,
	LifeStealAura = 12,
	MoveSpeedAura = 13,
	PetBat = 14,
	AreaHeal = 15,
	MoveSpeedReduction = 16,
	IncreasedMobTargeting = 17,
	PotionCooldownDecrease = 18,
	DodgeCooldownIncrease = 19,
	DodgeSpeedIncrease = 20,
	DodgeInvulnerability = 21,
	DamageAbsorption = 22,
	SlowResistance = 23,
	DodgeGhostForm = 24,
	Beekeeper = 25,
	DodgeRoot = 26,
	Heavyweight = 27,
	EnvironmentalProtection = 28,
	EmeraldShield = 29,
	ItemCooldownReset = 30,
	SquidRollQuick = 31,
	SquidRollLimited = 32,
	HealingAura = 33,
	FallResistance = 34,
	SquidRoll = 35,
	Resonant = 36,
	ImmunityBoost = 37,
	InstantTransmission = 38,
	Last = 39,
	EArmorPropertyID_MAX = 40
};


UENUM(BlueprintType) // Enum Dungeons.ELevelNames
enum class ELevelNames : uint8
{
	Invalid = 0,
	squidcoast = 1,
	creeperwoods = 2,
	pumpkinpastures = 3,
	soggyswamp = 4,
	mooncorecaverns = 5,
	fieryforge = 6,
	deserttemple = 7,
	slimysewers = 8,
	highblockhalls = 9,
	obsidianpinnacle = 10,
	cacticanyon = 11,
	creeperwoodsdaily = 12,
	creeperwoodsweekly = 13,
	creeperwoodsseasonal = 14,
	pumpkinpasturesdaily = 15,
	pumpkinpasturesweekly = 16,
	pumpkinpasturesseasonal = 17,
	soggyswampdaily = 18,
	soggyswampweekly = 19,
	soggyswampseasonal = 20,
	mooncorecavernsdaily = 21,
	mooncorecavernsweekly = 22,
	mooncorecavernsseasonal = 23,
	fieryforgedaily = 24,
	fieryforgeweekly = 25,
	fieryforgeseasonal = 26,
	deserttempledaily = 27,
	deserttempleweekly = 28,
	deserttempleseasonal = 29,
	slimysewersdaily = 30,
	slimysewersweekly = 31,
	slimysewersseasonal = 32,
	highblockhallsdaily = 33,
	highblockhallsweekly = 34,
	highblockhallsseasonal = 35,
	obsidianpinnacledaily = 36,
	obsidianpinnacleweekly = 37,
	obsidianpinnacleseasonal = 38,
	cacticanyondaily = 39,
	cacticanyonweekly = 40,
	cacticanyonseasonal = 41,
	creepycrypt = 42,
	soggycave = 43,
	underhalls = 44,
	archhaven = 45,
	lowertemple = 46,
	mooshroomisland = 47,
	woodlandmansion = 48,
	spidercave = 49,
	dingyjungle = 50,
	overgrowntemple = 51,
	bamboobluff = 52,
	frozenfjord = 53,
	lonelyfortress = 54,
	lostsettlement = 55,
	creepycryptdaily = 56,
	creepycryptweekly = 57,
	creepycryptseasonal = 58,
	soggycavedaily = 59,
	soggycaveweekly = 60,
	soggycaveseasonal = 61,
	underhallsdaily = 62,
	underhallsweekly = 63,
	underhallsseasonal = 64,
	archhavendaily = 65,
	archhavenweekly = 66,
	archhavenseasonal = 67,
	lowertempledaily = 68,
	lowertempleweekly = 69,
	lowertempleseasonal = 70,
	mooshroomislanddaily = 71,
	mooshroomislandweekly = 72,
	mooshroomislandseasonal = 73,
	dingyjungledaily = 74,
	dingyjungleweekly = 75,
	dingyjungleseasonal = 76,
	overgrowntempledaily = 77,
	overgrowntempleweekly = 78,
	overgrowntempleseasonal = 79,
	bamboobluffdaily = 80,
	bamboobluffweekly = 81,
	bamboobluffseasonal = 82,
	frozenfjorddaily = 83,
	frozenfjordweekly = 84,
	frozenfjordseasonal = 85,
	lonelyfortressdaily = 86,
	lonelyfortressweekly = 87,
	lonelyfortressseasonal = 88,
	lostsettlementdaily = 89,
	lostsettlementweekly = 90,
	lostsettlementseasonal = 91,
	crimsonforest = 92,
	basaltdeltas = 93,
	warpedforest = 94,
	soulsandvalley = 95,
	netherwastes = 96,
	netherfortress = 97,
	netherhypermission = 98,
	crimsonforestdaily = 99,
	crimsonforestweekly = 100,
	crimsonforestseasonal = 101,
	basaltdeltasdaily = 102,
	basaltdeltasweekly = 103,
	basaltdeltasseasonal = 104,
	warpedforestdaily = 105,
	warpedforestweekly = 106,
	warpedforestseasonal = 107,
	soulsandvalleydaily = 108,
	soulsandvalleyweekly = 109,
	soulsandvalleyseasonal = 110,
	netherwastesdaily = 111,
	netherwastesweekly = 112,
	netherwastesseasonal = 113,
	netherfortressdaily = 114,
	netherfortressweekly = 115,
	netherfortressseasonal = 116,
	windsweptpeaks = 117,
	galesanctum = 118,
	endlessrampart = 119,
	gauntletgales = 120,
	windsweptpeaksdaily = 121,
	windsweptpeaksweekly = 122,
	windsweptpeaksseasonal = 123,
	galesanctumdaily = 124,
	galesanctumweekly = 125,
	galesanctumseasonal = 126,
	endlessrampartdaily = 127,
	endlessrampartweekly = 128,
	endlessrampartseasonal = 129,
	gauntletgalesdaily = 130,
	gauntletgalesweekly = 131,
	gauntletgalesseasonal = 132,
	coralrise         = 133,
	abyssalmonument   = 134,
	radiantravine     = 135,
	coralrisedaily    = 136,
	coralriseweekly   = 137,
	coralriseseasonal = 138,
	abyssalmonumentdaily = 139,
	abyssalmonumentweekly = 140,
	abyssalmonumentseasonal = 141,
	radiantravinedaily = 142,
	radiantravineweekly = 143,
	radiantravineseasonal = 144,
	enderwilds           = 145,
	blightedcitadel   = 146,
	thestronghold     = 147,
	enderwildsdaily   = 148,
	enderwildsweekly  = 149,
	enderwildsseasonal = 150,
	blightedcitadeldaily = 151,
	blightedcitadelweekly = 152,
	blightedcitadelseasonal = 153,
	specialtileshub   = 154,
	hm_hub            = 155,
	count =            156,
	ELevelNames_MAX   = 157
};

// Enum Dungeons.ETitle
enum class ETitle : uint8_t
{
	ETitle__INVALID                = 0,
	ETitle__NONE                   = 1,
	ETitle__BOOMER                 = 2,
	ETitle__CREEPERS_BANE          = 3,
	ETitle__END                    = 4,
	ETitle__ETitle_MAX             = 5
};




UENUM(BlueprintType) // Enum Dungeons.EFriendsAddResponse
enum class EFriendsAddResponse : uint8
{
	Unset = 0,
	MissingParameter = 1,
	Searching = 2,
	NoMatch = 3,
	FriendAdded = 4,
	FriendAlreadyAdded = 5,
	GeneralError = 6
};


UENUM(BlueprintType) // Enum Dungeons.ESessionJoinFailureReason
enum class ESessionJoinFailureReason : uint8
{
	SessionIsFull = 0,
	SessionDoesNotExist = 1,
	CouldNotRetrieveAddress = 2,
	AlreadyInSession = 3,
	UnknownError = 4
};


UENUM(BlueprintType) // Enum Dungeons.ESessionFailureReason
enum class ESessionFailureReason : uint8
{
	CreateSessionFailed = 0,
	StartSessionFailed = 1,
	FindSessionsFailed = 2,
	JoinSessionFailed = 3,
	ConnectionStringResolutionFailed = 4,
	OnlineSystemNotAvailable = 5,
	InvalidPlayerController = 6,
	MapNameNotFound = 7,
	InvalidUniqueNetworkId = 8,
	SessionInterfaceUnavailable = 9,
	SessionNotFound = 10,
	InvalidFriendNetId = 11,
	LoginFailed = 12,
	Unknown = 13
};


UENUM(BlueprintType) // Enum Dungeons.EMapTrackingTypes
enum class EMapTrackingTypes : uint8
{
	ChestsOpened = 0,
	ChestsSpawned = 1,
	SecretsFound = 2,
	SecretsSpawned = 3,
	Size = 4
};


UENUM(BlueprintType) // Enum Dungeons.EPopupDialogType
enum class EPopupDialogType : uint8
{
	OK = 0,
	ConfirmCancel = 1
};


UENUM(BlueprintType) // Enum Dungeons.EGlobalMessageTypes
enum class EGlobalMessageTypes : uint8
{
	Unset = 0,
	ClientKicked = 1,
	InviteTimedOut = 2,
	ConnectionTimeout = 3,
	NoInternetConnection = 4,
	NotConnectedToOnlineService = 5,
	DisconnectedFromHost = 6,
	FailedToCreate = 7,
	CrossPlayDisabled = 8,
	PS4CrossplayDisabled = 9,
	PS4CrossplayEnabled = 10,
	JoinPermissionError = 11
};


UENUM(BlueprintType) // Enum Dungeons.ELoginResult
enum class ELoginResult : uint8
{
	Success = 0,
	InternalError = 1,
	UserAlreadyInGame = 2,
	UserCanceledLogin = 3,
	FailedMsaLogin = 4,
	NetworkIssue = 5,
	ThisPsnAlreadyLinkedToDifferentMSA = 6,
	LinkingError = 7,
	LinkingGuestAccountError = 8,
	ThisMsaAlreadyLinkedToDifferentPSN = 9,
	PlayfabLoginFailedCrossplayUnavailable = 10,
	SpopIssue = 11
};


UENUM(BlueprintType) // Enum Dungeons.ELocalUserLoginResult
enum class ELocalUserLoginResult : uint8
{
	Success = 0,
	UserAlreadyInGame = 1,
	Error = 2
};


UENUM(BlueprintType) // Enum Dungeons.ENotificationType
enum class ENotificationType : uint8
{
	Invalid = 0,
	Event = 1,
	PlayerJoin = 2,
	SelfGearPickup = 3,
	OtherGearPickup = 4
};


UENUM(BlueprintType) // Enum Dungeons.EEventType
enum class EEventType : uint8
{
	None = 0,
	ArenaBattle = 1,
	Boss = 2,
	DoorOpened = 3,
	SideQuestBattle = 4
};


UENUM(BlueprintType) // Enum Dungeons.EPillarState
enum class EPillarState : uint8
{
	Inactive = 0,
	Active = 1,
	DrainCharge = 2,
	RegenerateCharge = 3,
	RapidRecharging = 4,
	TimedDelay = 5,
	Depleted = 6,
	Defeated = 7
};


UENUM(BlueprintType) // Enum Dungeons.ELobbyChestLootType
enum class ELobbyChestLootType : uint8
{
	Static = 0,
	RandomItem = 1,
	RandomGear = 2,
	Emeralds = 3
};


UENUM(BlueprintType) // Enum Dungeons.EGameDifficulty
enum class EGameDifficulty : uint8
{
	Invalid = 0,
	Difficulty = 1,
	Difficulty01 = 2,
	Difficulty02 = 3,
	ENUM_COUNT = 4
};


UENUM(BlueprintType) // Enum Dungeons.EMissionDifficultyCompletionLogic
enum class EMissionDifficultyCompletionLogic : uint8
{
	DISABLED = 0,
	Any = 1,
	UseCount = 2,
	UseLevelID = 3
};


UENUM(BlueprintType) // Enum Dungeons.ELobbyChestType
enum class ELobbyChestType : uint8
{
	UNSET = 0,
	Chest = 1,
	Blacksmith = 2,
	Librarian = 3,
	Villager = 4,
	TravelingMerchant = 5
};


UENUM(BlueprintType) // Enum Dungeons.EDLCName
enum class EDLCName : uint8
{
	Invalid = 0,
	TheJungleAwakens = 1,
	TheCreepingWinter = 2,
	Mountains = 3,
	Nether = 4,
	Oceans = 5,
	TheEnd = 6,
	count = 7
};


UENUM(BlueprintType) // Enum Dungeons.EThreatLevel
enum class EThreatLevel : uint8
{
	Invalid = 0,
	Threat = 1,
	Threat01 = 2,
	Threat02 = 3,
	Threat03 = 4,
	Threat04 = 5,
	Threat05 = 6,
	Threat06 = 7,
	ENUM_COUNT = 8
};


UENUM(BlueprintType) // Enum Dungeons.EUIHintType
enum class EUIHintType : uint8
{
	None = 0,
	Movement = 1,
	Objective = 2,
	DefeatZombie = 3,
	LowHealth = 4,
	PickupArrow = 5,
	RangedAttack = 6,
	Artifact_Pickup = 7,
	Artifact_OpenInventory = 8,
	Artifact_Equip = 9,
	Artifact_Activate = 10,
	Artifact_RangedAttack = 11,
	Enchanting_OpenInventory = 12,
	Enchanting_SelectGear = 13,
	Enchanting_SelectEnchantment = 14,
	Enchanting_ItemEnchanted = 15,
	MissionSelect_Marker = 16,
	MissionSelect_Popup = 17,
	Merchants_FindMerchants = 18,
	Merchants_Interact = 19,
	Map = 20,
	Teleport = 21,
	Popping = 22,
	ChatWheel_Open = 23,
	ChatWheel_Select = 24,
	ChatWheel_Chat = 25,
	Merchants_Reserve = 26,
	ENUM_COUNT = 27
};


UENUM(BlueprintType) // Enum Dungeons.EVisibilityReason
enum class EVisibilityReason : uint8
{
	Activated = 0,
	Completed = 1,
	Forgot = 2
};


UENUM(BlueprintType) // Enum Dungeons.ETeleportState
enum class ETeleportState : uint8
{
	Idle = 0,
	Charging = 1,
	Flying = 2,
	Landing = 3
};


UENUM(BlueprintType) // Enum Dungeons.TempestArmStatus
enum class ETempestArmStatus : uint8
{
	ACTIVE = 0,
	ATTACKING = 1,
	DISABLED = 2,
	DISABLING = 3,
	REACTIVATING = 4,
	INVALID = 5,
	TRACKING = 6,
	LOCKED = 7
};


UENUM(BlueprintType) // Enum Dungeons.TempestStatus
enum class ETempestStatus : uint8
{
	INVALID = 0,
	INTRO = 1,
	ACTIVE = 2,
	STUNNED = 3
};


UENUM(BlueprintType) // Enum Dungeons.EEndGameContentType
enum class EEndGameContentType : uint8
{
	Invalid = 0,
	EndlessStruggle = 1,
	HyperMission = 2,
	ENUM_COUNT = 3
};


UENUM(BlueprintType) // Enum Dungeons.EFetchTitleNewsFailReason
enum class EFetchTitleNewsFailReason : uint8
{
	RandomThingWentWrong = 0,
	CouldntReachNews = 1,
	MalformedJson = 2,
	MissingWorld = 3,
	Unknown = 4
};


UENUM(BlueprintType) // Enum Dungeons.EMissionTheme
enum class EMissionTheme : uint8
{
	Invalid = 0,
	Story = 1,
	Secret = 2,
	Daily = 3,
	Weekly = 4,
	Seasonal = 5,
	Spooky = 6,
	Jungle = 7,
	Winter = 8,
	Mountain = 9,
	Hypermission = 10,
	count = 11
};


UENUM(BlueprintType) // Enum Dungeons.ECloudCharactersResult
enum class ECloudCharactersResult : uint8
{
	Failed = 0,
	FailedAccountNotLinked = 1,
	FailedLogin = 2,
	Success = 3
};


UENUM(BlueprintType) // Enum Dungeons.EAffectorId
enum class EAffectorId : uint8
{
	EmeraldHealthAdd = 0,
	PlayerArrowType = 1,
	PlayerDamage = 2,
	PlayerHealth = 3,
	PlayerSpeed = 4,
	PlayerArtifactCooldown = 5,
	MobDamage = 6,
	MobHealth = 7,
	MobSpeed = 8,
	MobInvisible = 9,
	NightMode = 10,
	PetCount = 11,
	InstantGameOver = 12,
	SoulCount = 13,
	StartupLives = 14,
	ReplaceMeleeMobs = 15,
	ReplaceRangedMobs = 16,
	PlayerEnchantment = 17,
	MobEnchantment = 18,
	ChestProbability = 19,
	Last = 20
};


UENUM(BlueprintType) // Enum Dungeons.EAffectorModus
enum class EAffectorModus : uint8
{
	Easier = 0,
	Harder = 1,
	Any = 2
};


UENUM(BlueprintType) // Enum Dungeons.EAmbienceAudioID
enum class EAmbienceAudioID : uint8
{
	AUDIO_FROM_AMBIENCE = 0,
	AUDIO = 1,
	AUDIO01 = 2,
	AUDIO02 = 3,
	AUDIO03 = 4,
	AUDIO04 = 5,
	AUDIO05 = 6,
	AUDIO06 = 7,
	AUDIO07 = 8,
	AUDIO08 = 9
};


UENUM(BlueprintType) // Enum Dungeons.EAmbienceID
enum class EAmbienceID : uint8
{
	AMBIENCE_DEFAULT = 0,
	AMBIENCE_ALPHA = 1,
	AMBIENCE_BRAVO = 2,
	AMBIENCE_DELTA = 3,
	AMBIENCE_ECHO = 4,
	AMBIENCE_FOXTROT = 5
};


UENUM(BlueprintType) // Enum Dungeons.ETelemetryEventType
enum class ETelemetryEventType : uint8
{
	GameSessionStartup = 0,
	OnDeath = 1,
	OnRateMission = 2,
	OnCheckpoint = 3,
	RoundAwards = 4,
	OnLevelStart = 5,
	OnJoinLobby = 6,
	OnLevelJoin = 7,
	OnChatWheel = 8,
	OnTextChatUse = 9,
	OnObjectiveDone = 10,
	GameSessionEnd = 11,
	Logout = 12,
	SettingsChange = 13,
	OnMobKilled = 14,
	Assert = 15,
	CrashDetected = 16,
	Count = 17
};


UENUM(BlueprintType) // Enum Dungeons.EArmorPropertyTag
enum class EArmorPropertyTag : uint8
{
	SoulGatheringBoost = 0
};


UENUM(BlueprintType) // Enum Dungeons.EArmorPropertyClassification
enum class EArmorPropertyClassification : uint8
{
	Positive = 0,
	Negative = 1
};


UENUM(BlueprintType) // Enum Dungeons.ESuccessFailure
enum class ESuccessFailure : uint8
{
	Success = 0,
	Failure = 1
};


UENUM(BlueprintType) // Enum Dungeons.ESynchornizedCollisionResponse
enum class ESynchornizedCollisionResponse : uint8
{
	Default = 0,
	WorldOnly = 1
};


UENUM(BlueprintType) // Enum Dungeons.EMobState
enum class EMobState : uint8
{
	Idle = 0,
	Combat = 1,
	Staggered = 2,
	Fleeing = 3,
	Custom1 = 4
};


UENUM(BlueprintType) // Enum Dungeons.EAttackState
enum class EAttackState : uint8
{
	None = 0,
	Aiming = 1,
	Melee = 2,
	Ranged = 3,
	Magic = 4,
	Targeting = 5
};


UENUM(BlueprintType) // Enum Dungeons.ECharacterWorldState
enum class ECharacterWorldState : uint8
{
	InWorld = 0,
	Disappeared = 1,
	DisappearedWithCollision = 2
};


UENUM(BlueprintType) // Enum Dungeons.EMovementState
enum class EMovementState : uint8
{
	Idle = 0,
	Walking = 1,
	Running = 2,
	Flying = 3,
	Staggered = 4,
	Dashing = 5,
	Rolling = 6,
	Usingitem = 7
};


UENUM(BlueprintType) // Enum Dungeons.EPlayerInputType
enum class EPlayerInputType : uint8
{
	Movement = 0,
	Attack = 1,
	Hotbar = 2,
	Map = 3,
	Inventory = 4,
	Teleport = 5,
	Social = 6,
	TextChat = 7,
	UI = 8,
	Debug = 9
};


UENUM(BlueprintType) // Enum Dungeons.ELocalPlayerCameraStatus
enum class ELocalPlayerCameraStatus : uint8
{
	InCinematic = 0,
	InSafeZone = 1,
	InDangerZone = 2,
	InHardBoundary = 3,
	OffScreen = 4
};


UENUM(BlueprintType) // Enum Dungeons.EPlayerStatusType
enum class EPlayerStatusType : uint8
{
	UNSET = 0,
	Joined = 1,
	Left = 2
};


UENUM(BlueprintType) // Enum Dungeons.EBlockingMessageType
enum class EBlockingMessageType : uint8
{
	Unset = 0,
	SourceAuthenticationFailed = 1,
	MissingBaseGameEntitlement = 2,
	EntitlementsRequestFailed = 3
};


UENUM(BlueprintType) // Enum Dungeons.EAnimLocomotion
enum class EAnimLocomotion : uint8
{
	Idle = 0,
	WalkRun = 1,
	Flying = 2,
	BlendSpace = 3,
	Falling = 4,
	DownedDead = 5
};


UENUM(BlueprintType) // Enum Dungeons.EChatMessageType
enum class EChatMessageType : uint8
{
	UNSET = 0,
	Text = 1,
	Icon = 2,
	Item = 3,
	Status = 4
};


UENUM(BlueprintType) // Enum Dungeons.EChestType
enum class EChestType : uint8
{
	Wooden = 0,
	Fancy = 1,
	Deluxe = 2
};


UENUM(BlueprintType) // Enum Dungeons.ESourceState
enum class ESourceState : uint8
{
	Pending = 0,
	RequestSent = 1,
	Failed = 2,
	Succeeded = 3
};


UENUM(BlueprintType) // Enum Dungeons.ECosmeticType
enum class ECosmeticType : uint8
{
	Unset = 0,
	Cape = 1,
	Pet = 2,
	Invalid = 3
};


UENUM(BlueprintType) // Enum Dungeons.EUICounterEmphasis
enum class EUICounterEmphasis : uint8
{
	Regular = 0,
	Diminished = 1,
	Emphasized = 2
};


UENUM(BlueprintType) // Enum Dungeons.EPlayerPlatform
enum class EPlayerPlatform : uint8
{
	PC_PLATFORM = 0,
	XBOXONE_PLATFORM = 1,
	SWITCH_PLATFORM = 2,
	PS4_PLATFORM = 3,
	UNKNOWN = 4
};


UENUM(BlueprintType) // Enum Dungeons.EClickTargetType
enum class EClickTargetType : uint8
{
	Target = 0,
	Clicky = 1
};


UENUM(BlueprintType) // Enum Dungeons.ESessionOnlineService
enum class ESessionOnlineService : uint8
{
	PSN = 0,
	XBL = 1,
	UNKNOWN = 2
};


UENUM(BlueprintType) // Enum Dungeons.EAwardType
enum class EAwardType : uint8
{
	Invalid = 0,
	MostEnemiesHit = 1,
	MostDamageDoneSingleBlow = 2,
	MostEnemiesKilled = 3,
	MostZombiesKilled = 4,
	MostSkeletonsKilled = 5,
	MostSpidersKilled = 6,
	MostDamageDone = 7,
	BlocksWalkedOn = 8,
	MostArrowsFired = 9,
	MostArrowsHit = 10,
	StrengthPotionsUsed = 11,
	SwiftnessPotionsUsed = 12,
	TNTUsed = 13,
	HealthPotionsUsed = 14,
	ItemsUsed = 15,
	LeastDamageTaken = 16,
	GameMobsKilled = 17
};


UENUM(BlueprintType) // Enum Dungeons.ELowSpecNotifyType
enum class ELowSpecNotifyType : uint8
{
	OnBatteryPower = 0,
	LowMemory = 1,
	LowPerformance = 2
};


UENUM(BlueprintType) // Enum Dungeons.SwitchOperationMode
enum class ESwitchOperationMode : uint8
{
	Handheld = 0,
	Console = 1
};


UENUM(BlueprintType) // Enum Dungeons.StatusEnum
enum class EStatusEnum : uint8
{
	Success = 0,
	Fail = 1
};


UENUM(BlueprintType) // Enum Dungeons.EDungeonsControllerType
enum class EDungeonsControllerType : uint8
{
	MouseAndKeyboard = 0,
	XboxOne = 1,
	Touch = 2,
	Virtual = 3,
	PS4 = 4,
	SwitchHandheld = 5,
	SwitchPro = 6,
	SwitchJoyconDual = 7,
	SwitchJoyconLeft = 8,
	SwitchJoyconRight = 9,
	Invalid = 10
};


UENUM(BlueprintType) // Enum Dungeons.EMapLoadType
enum class EMapLoadType : uint8
{
	Unset = 0,
	StartLobbySession = 1,
	StartIngameSession = 2,
	OpenMenu = 3,
	OpenIngame = 4,
	OpenLobby = 5,
	TravelIngameServer = 6,
	TravelIngameClient = 7,
	TravelLobbyServer = 8,
	TravelLobbyClient = 9,
	JoinIngameSession = 10,
	JoinLobbySession = 11
};


UENUM(BlueprintType) // Enum Dungeons.ELoadingScreenType
enum class ELoadingScreenType : uint8
{
	Menu = 0,
	Level = 1,
	Lobby = 2,
	Count = 3
};


UENUM(BlueprintType) // Enum Dungeons.EFriendInvitableStatus
enum class EFriendInvitableStatus : uint8
{
	Invitable = 0,
	BlockedDifferentPlatform = 1,
	BlockedInactive = 2,
	BlockedOnewayFriend = 3,
	BlockedSessionClosed = 4,
	BlockedInvalidPlayerId = 5,
	BlockedUnknownReason = 6,
	BlockedCrossplayEnabled = 7,
	BlockedCrossplayDisabled = 8
};


UENUM(BlueprintType) // Enum Dungeons.EFriendOnlineService
enum class EFriendOnlineService : uint8
{
	PSN = 0,
	XBL = 1
};


UENUM(BlueprintType) // Enum Dungeons.EFriendOnlineStatus
enum class EFriendOnlineStatus : uint8
{
	InGameSession = 0,
	Online = 1,
	Offline = 2
};


UENUM(BlueprintType) // Enum Dungeons.EFriendsFailureReason
enum class EFriendsFailureReason : uint8
{
	OnlineSystemNotAvailable = 0,
	InvalidPlayerController = 1,
	FriendsSubSystemNotAvailable = 2,
	InvalidUniqueNetworkId = 3,
	Unknown = 4
};


UENUM(BlueprintType) // Enum Dungeons.EBootMode
enum class EBootMode : uint8
{
	Unset = 0,
	InitialBoot = 1,
	SwitchUser = 2,
	UserSignedOut = 3
};


UENUM(BlueprintType) // Enum Dungeons.EStackCountDisplayPreference
enum class EStackCountDisplayPreference : uint8
{
	AsCounter = 0,
	AsPercentage = 1
};


UENUM(BlueprintType) // Enum Dungeons.EGameTrackingTypes
enum class EGameTrackingTypes : uint8
{
	ChestsOpened = 0,
	ChestsSpawned = 1,
	DamageDealt = 2,
	EmeraldsFound = 3,
	EmeraldsSpawned = 4,
	GearSpawned = 5,
	GearPickedUp = 6,
	MobsSpawned = 7,
	MobsKilled = 8,
	PlayerDamageTaken = 9,
	PlayerDeaths = 10,
	PlayerHealingDone = 11,
	PlayerProjectileFired = 12,
	PlayerProjectileHit = 13,
	Size = 14
};


UENUM(BlueprintType) // Enum Dungeons.CameraShakeSamplerOffsetType
enum class ECameraShakeSamplerOffsetType : uint8
{
	Relative = 0,
	Absolute = 1,
	InverseAbsolute = 2
};


UENUM(BlueprintType) // Enum Dungeons.EEmote
enum class EEmote : uint8
{
	INVALID = 0,
	ComeHere = 1,
	Thanks = 2,
	Ok = 3,
	NeedArrows = 4,
	Wait = 5,
	NeedHealth = 6,
	No = 7,
	SuppliesHere = 8,
	COUNT = 9
};


UENUM(BlueprintType) // Enum Dungeons.EEnchantersTomeFlags
enum class EEnchantersTomeFlags : uint8
{
	None = 0,
	Absolute = 1,
	Pet = 2,
	Player = 3
};

UENUM(BlueprintType) // Enum Dungeons.EEnchantmentTag
enum class EEnchantmentTag : uint8
{
	Stacking = 0,
	Multi = 1,
	SoulUsage = 2,
	ChargingWeaponsOnly = 3
};


UENUM(BlueprintType) // Enum Dungeons.EEnchantmentRarity
enum class EEnchantmentRarity : uint8
{
	Common = 0,
	Powerful = 1
};


UENUM(BlueprintType) // Enum Dungeons.EEnchantmentClassification
enum class EEnchantmentClassification : uint8
{
	Unset = 0,
	Damage = 1,
	Offense = 2,
	Defense = 3
};

UENUM(BlueprintType) // Enum Dungeons.EEntitlementsSource
enum class EEntitlementsSource : uint8
{
	Invalid = 0,
	Development = 1,
	MinecraftNet = 2,
	WindowsStore = 3,
	XBL = 4,
	PSN = 5,
	Nintendo = 6
};


UENUM(BlueprintType) // Enum Dungeons.EntityType
enum class EntityType : uint8
{
	Undefined = 0,
	ItemEntity = 1,
	PrimedTnt = 2,
	FallingBlock = 3,
	MovingBlock = 4,
	ExperiencePotion = 5,
	Experience = 6,
	EyeOfEnder = 7,
	EnderCrystal = 8,
	ShulkerBullet = 9,
	FishingHook = 10,
	Chalkboard = 11,
	DragonFireball = 12,
	Arrow = 13,
	Snowball = 14,
	ThrownEgg = 15,
	Painting = 16,
	LargeFireball = 17,
	ThrownPotion = 18,
	Enderpearl = 19,
	LeashKnot = 20,
	WitherSkull = 21,
	BoatRideable = 22,
	WitherSkullDangerous = 23,
	LightningBolt = 24,
	SmallFireball = 25,
	AreaEffectCloud = 26,
	LingeringPotion = 27,
	TypeMask = 28,
	Mob = 29,
	Monster = 30,
	Animal = 31,
	WaterAnimal = 32,
	TamableAnimal = 33,
	Ambient = 34,
	UndeadMob = 35,
	ZombieMonster = 36,
	Arthropod = 37,
	Minecart = 38,
	SkeletonMonster = 39,
	EquineAnimal = 40,
	Chicken = 41,
	Cow = 42,
	Pig = 43,
	Sheep = 44,
	Wolf = 45,
	Villager = 46,
	Mooshroom = 47,
	MooshroomAncient = 48,
	Squid = 49,
	Rabbit = 50,
	Bat = 51,
	IronGolem = 52,
	SnowGolem = 53,
	Horse = 54,
	Donkey = 55,
	Mule = 56,
	SkeletonHorse = 57,
	ZombieHorse = 58,
	RedstoneGolem = 59,
	RedstoneGolemAncient = 60,
	Enchanter = 61,
	EnchanterAncient = 62,
	Vindicator = 63,
	VindicatorVariant0 = 64,
	VindicatorVariant1 = 65,
	VindicatorVariant2 = 66,
	BabyZombie = 67,
	BabyZombieAncient = 68,
	Zombie = 69,
	ZombieVariant0 = 70,
	ZombieVariant1 = 71,
	ZombieVariant2 = 72,
	ZombieAncient = 73,
	Creeper = 74,
	Skeleton = 75,
	SkeletonVariant0 = 76,
	SkeletonVariant1 = 77,
	SkeletonVariant2 = 78,
	SkeletonAncient = 79,
	Spider = 80,
	SpiderAncient = 81,
	ZombifiedPiglin = 82,
	Silverfish = 83,
	CaveSpider = 84,
	Ghast = 85,
	Blaze = 86,
	ZombieVillager = 87,
	Witch = 88,
	WitchAncient = 89,
	Stray = 90,
	Husk = 91,
	WitherSkeleton = 92,
	WitherSkeletonRanged = 93,
	PiglinFungusThrower = 94,
	ZombifiedPiglinFungusThrower = 95,
	Guardian = 96,
	ElderGuardian = 97,
	Npc = 98,
	WitherBoss = 99,
	Dragon = 100,
	Shulker = 101,
	Endermite = 102,
	Agent = 103,
	Necromancer = 104,
	NecromancerAncient = 105,
	Vex = 106,
	VexAncient = 107,
	Evoker = 108,
	EvokerFang = 109,
	Geomancer = 110,
	GeomancerAncient = 111,
	TripodCamera = 112,
	Player = 113,
	GeomancerWall = 114,
	GeomancerBomb = 115,
	ChickenJockey = 116,
	ChickenJockeyTower = 117,
	ChickenJockeyTowerAncient = 118,
	SlimeLarge = 119,
	SlimeMedium = 120,
	SlimeSmall = 121,
	SlimeSmallAncient = 122,
	RedstoneMonstrosity = 123,
	Wraith = 124,
	WraithAncient = 125,
	RedstoneCube = 126,
	PiggyBank = 127,
	GoldBabyKey = 128,
	SilverBabyKey = 129,
	NamelessKing = 130,
	Pillager = 131,
	PillagerVariant0 = 132,
	PillagerVariant1 = 133,
	PillagerVariant2 = 134,
	PillagerAncient = 135,
	FalseKing = 136,
	SkeletonVanguard = 137,
	SkeletonVanguardAncient = 138,
	MobSpawner = 139,
	SkeletonHorseman = 140,
	OrdinaryHorse = 141,
	CauldronBoss = 142,
	SlimeCauldron = 143,
	ArchIllager = 144,
	ArchVessel = 145,
	ArchVisage = 146,
	JackOLantern = 147,
	RoyalGuard = 148,
	RoyalGuardAncient = 149,
	VindicatorChef = 150,
	Llama = 151,
	SoulWizard = 152,
	Enderman = 153,
	MinecartHopper = 154,
	MinecartTNT = 155,
	MinecartChest = 156,
	MinecartFurnace = 157,
	MooshroomMonstrosity = 158,
	BabyChicken = 159,
	ChargedCreeper = 160,
	BabyPig = 161,
	Dummy = 162,
	JungleZombie = 163,
	MossySkeleton = 164,
	QuickGrowingVine = 165,
	PoisonQuillVine = 166,
	Ocelot = 167,
	PlayfulPanda = 168,
	LazyPanda = 169,
	BrownPanda = 170,
	Leaper = 171,
	LeaperAncient = 172,
	Whisperer = 173,
	JungleAbomination = 174,
	QuickGrowingVineSimple = 175,
	PoisonQuillVineSimple = 176,
	EntangleVine = 177,
	AbominationVine = 178,
	BabyPanda = 179,
	Parrot = 180,
	Panda = 181,
	FrozenZombie = 182,
	IcyCreeper = 183,
	PolarBear = 184,
	ArcticFox = 185,
	Illusioner = 186,
	IllusionerClone = 187,
	Chillager = 188,
	WickedWraith = 189,
	Bee = 190,
	SheepFireRed = 191,
	SheepPoisonGreen = 192,
	SheepSpeedBlue = 193,
	Goat = 194,
	GoatAncient = 195,
	Ravager = 196,
	WoolyCow = 197,
	LlamaMob = 198,
	WindCaller = 199,
	BabyGoat = 200,
	SquallGolem = 201,
	Mountaineer = 202,
	MountaineerVariant0 = 203,
	MountaineerVariant1 = 204,
	MountaineerVariant2 = 205,
	TempestGolem = 206,
	RampartCaptain = 207,
	BlazeSpawner = 208,
	BlazeSpawnerAncient = 209,
	HoveringInferno = 210,
	Hoglin = 211,
	HoglinAncient = 212,
	PiglinMelee = 213,
	PiglinMeleeVariant0 = 214,
	PiglinMeleeVariant1 = 215,
	PiglinMeleeVariant2 = 216,
	PiglinRanged = 217,
	PiglinRangedVariant0 = 218,
	PiglinRangedVariant1 = 219,
	PiglinRangedVariant2 = 220,
	ZombifiedPiglinMelee = 221,
	ZombifiedPiglinMeleeVariant0 = 222,
	ZombifiedPiglinMeleeVariant1 = 223,
	ZombifiedPiglinMeleeVariant2 = 224,
	ZombifiedPiglinRanged = 225,
	ZombifiedPiglinRangedVariant0 = 226,
	ZombifiedPiglinRangedVariant1 = 227,
	ZombifiedPiglinRangedVariant2 = 228,
	BabyGhast = 229,
	MagmaCubeLarge = 230,
	MagmaCubeMedium = 231,
	MagmaCubeSmall = 232
};


UENUM(BlueprintType) // Enum Dungeons.EMessageType
enum class EMessageType : uint8
{
	OneButton = 0,
	TwoButton = 1
};


UENUM(BlueprintType) // Enum Dungeons.EExtraChallenge
enum class EExtraChallenge : uint8
{
	Invalid = 0,
	NoExtraChallenge = 1,
	Challenge = 2,
	Challenge01 = 3,
	Challenge02 = 4,
	ENUM_COUNT = 5
};


UENUM(BlueprintType) // Enum Dungeons.EHierarchyPlacementComparison
enum class EHierarchyPlacementComparison : uint8
{
	Above = 0,
	Below = 1,
	Same = 2,
	None = 3
};


UENUM(BlueprintType) // Enum Dungeons.AGameBPInternal_EServerLoadingState
enum class EAGameBPInternal_EServerLoadingState : uint8
{
	Loading = 0,
	ReadyForPlayers = 1,
	Started = 2
};


UENUM(BlueprintType) // Enum Dungeons.EEntitlementRequestor
enum class EEntitlementRequestor : uint8
{
	Title = 0,
	Game = 1
};


UENUM(BlueprintType) // Enum Dungeons.NavAreaType
enum class ENavAreaType : uint8
{
	Ground = 0,
	Lava = 1
};


UENUM(BlueprintType) // Enum Dungeons.EPresetValue
enum class EPresetValue : uint8
{
	Off = 0,
	Low = 1,
	Medium = 2,
	High = 3,
	On = 4
};


UENUM(BlueprintType) // Enum Dungeons.EEnemyOutlineColours
enum class EEnemyOutlineColours : uint8
{
	Red = 0,
	Orange = 1,
	Yellow = 2,
	Gold = 3,
	Green = 4,
	MintGreen = 5,
	Pink = 6,
	Magenta = 7,
	Purple = 8,
	Lavender = 9,
	White = 10
};

UENUM(BlueprintType) // Enum Dungeons.EConfigurationType
enum class EConfigurationType : uint8
{
	DEBUG = 0,
	DEVELOPMENT = 1,
	TEST = 2,
	SHIPPING = 3
};


UENUM(BlueprintType) // Enum Dungeons.ESubPlatformType
enum class ESubPlatformType : uint8
{
	BASE = 0,
	XBONE_S = 1,
	XBONE_X = 2,
	XBONE_LOCKHART = 3,
	XBONE_SERIES_X = 4,
	PS4_PRO = 5,
	PS5 = 6
};


UENUM(BlueprintType) // Enum Dungeons.EPlatformType
enum class EPlatformType : uint8
{
	XBONE = 0,
	PC = 1,
	PS4 = 2,
	SWITCH = 3,
	MAC = 4,
	IOS = 5,
	ANDROID = 6,
	LINUX = 7
};

UENUM(BlueprintType) // Enum Dungeons.EDamageComponent
enum class EDamageComponent : uint8
{
	Default = 0,
	Melee = 1,
	Projectile = 2,
	Explosion = 3,
	Fall = 4,
	Potion = 5,
	AOE = 6,
	Item = 7,
	Harvester = 8,
	Magic = 9,
	KillZone = 10
};


UENUM(BlueprintType) // Enum Dungeons.ESpawnActorSnappingMode
enum class ESpawnActorSnappingMode : uint8
{
	None = 0,
	SnapXY = 1,
	Snap = 2
};


UENUM(BlueprintType) // Enum Dungeons.ESpawnActorDefaultTransform
enum class ESpawnActorDefaultTransform : uint8
{
	ProjectileTransform = 0,
	ImpactLocation = 1,
	BelowCharacter = 2
};


UENUM(BlueprintType) // Enum Dungeons.EImpactTriggerType
enum class EImpactTriggerType : uint8
{
	Final = 0,
	Always = 1
};


UENUM(BlueprintType) // Enum Dungeons.EBalloonItemDescriptionBehavior
enum class EBalloonItemDescriptionBehavior : uint8
{
	Detailed = 0,
	Collapsed = 1
};


UENUM(BlueprintType) // Enum Dungeons.EBalloonTipBehavior
enum class EBalloonTipBehavior : uint8
{
	AlwaysVisible = 0,
	VisibleOnHover = 1,
	Hidden = 2
};


UENUM(BlueprintType) // Enum Dungeons.EEffectLevelSource
enum class EEffectLevelSource : uint8
{
	RangedWeapon = 0,
	SourceItem = 1
};


UENUM(BlueprintType) // Enum Dungeons.EItemAnnouncementType
enum class EItemAnnouncementType : uint8
{
	UNSET = 0,
	PURCHASED = 1,
	GIFT_SENT = 2,
	GIFT_RECEIVED = 3,
	UPGRADED = 4,
	COLLECTED = 5,
	RECEIVED = 6
};


UENUM(BlueprintType) // Enum Dungeons.EItemArchetype
enum class EItemArchetype : uint8
{
	Acrobat = 0,
	Archer = 1,
	Fighter = 2,
	Mage = 3,
	Soul = 4,
	Summoner = 5,
	Support = 6,
	Tank = 7,
	Special = 8
};

UENUM(BlueprintType) // Enum Dungeons.EBulletIcon
enum class EBulletIcon : uint8
{
	Generic = 0,
	ItemPower = 1,
	SoulGather = 2,
	SoulUse = 3,
	Cooldown = 4,
	Common = 5,
	Rare = 6,
	Unique = 7,
	Netherite = 8,
	SeasonalLimited = 9,
	EnchantmentPoint = 10,
	Archetype = 11,
	Gold = 12
};

UENUM(BlueprintType) // Enum Dungeons.EDropGeneratorCategory
enum class EDropGeneratorCategory : uint8
{
	Food = 0,
	Consumable = 1,
	Arrow = 2,
	Emerald = 3,
	Gold = 4,
	Gear = 5,
	PermanentItem = 6,
	LootTable = 7,
	LootTableIncludeChildren = 8
};


UENUM(BlueprintType) // Enum Dungeons.EDropCategory
enum class EDropCategory : uint8
{
	Food = 0,
	Consumable = 1,
	Arrow = 2,
	Emerald = 3,
	Gold = 4,
	Gear = 5,
	None = 6,
	PermanentItem = 7
};


UENUM(BlueprintType) // Enum Dungeons.EDropSpawnType
enum class EDropSpawnType : uint8
{
	All = 0,
	Individual = 1,
	Shared = 2
};


UENUM(BlueprintType) // Enum Dungeons.EClickyEnum
enum class EClickyEnum : uint8
{
	MapTable = 0,
	Inventory = 1,
	LobbyChest = 2,
	Interactable = 3,
	Item = 4,
	IceBlock = 5,
	Merchant = 6,
	Disabled = 7
};


UENUM(BlueprintType) // Enum Dungeons.EEquipmentSlot
enum class EEquipmentSlot : uint8
{
	HotbarSlot1 = 0,
	HotbarSlot2 = 1,
	HotbarSlot3 = 2,
	MeleeGear = 3,
	RangedGear = 4,
	ArmorGear = 5,
	Invalid = 6
};


UENUM(BlueprintType)// Enum Dungeons.EItemPowerComparison
enum class EItemPowerComparison : uint8
{
	NONE = 0,
	Better = 1,
	Same = 2,
	Worse = 3
};


UENUM(BlueprintType) // Enum Dungeons.EItemStats
enum class EItemStats : uint8
{
	Invalid = 0,
	AverageDamage = 1,
	AttackSpeed = 2,
	QuiverAmmo = 3,
	AreaDamage = 4,
	DamagePerSec = 5,
	DamagePerQuiver = 6,
	DamagePerVolley = 7,
	ArrowSpeed = 8,
	AverageArea = 9,
	PushbackStr = 10,
	HitSnappiness = 11,
	RechargeSpeed = 12,
	LowestDamage = 13,
	HighestDamage = 14,
	DamagePerSecond = 15,
	ProjectilesPerAttack = 16,
	DamageBoost = 17,
	LowestHealthHealed = 18,
	HighestHealthHealed = 19,
	StunDuration = 20,
	BlocksPushed = 21,
	Health = 22,
	NUM_ESTIMATES = 23
};


UENUM(BlueprintType) // Enum Dungeons.EItemEventType
enum class EItemEventType : uint8
{
	None = 0,
	Spooky = 1,
	Winter = 2
};


UENUM(BlueprintType) // Enum Dungeons.RangedWeaponType
enum class ERangedWeaponType : uint8
{
	None = 0,
	Bow = 1,
	Crossbow = 2
};


UENUM(BlueprintType) // Enum Dungeons.ESlotType
enum class ESlotType : uint8
{
	HealthPotion = 0,
	Arrow = 1,
	BurningArrow = 2,
	FireworksArrow = 3,
	TormentProjectile = 4,
	HeavyHarpoon = 5,
	ThunderingArrow = 6,
	TNT = 7,
	Trident = 8,
	Conduit = 9,
	ActivePermanent = 10,
	Consumable = 11,
	MeleeWeapon = 12,
	RangedWeapon = 13,
	Armor = 14,
	Any = 15,
	None = 16,
	Last = 17
};

UENUM(BlueprintType) // Enum Dungeons.ItemTagLevel
enum class EItemTagLevel : uint8
{
	Normal = 0,
	Bright = 1,
	Diamond = 2,
	Last = 3
};


UENUM(BlueprintType) // Enum Dungeons.ItemTag
enum class EItemTag : uint8
{
	Unset = 0,
	HealthPotion = 1,
	Arrow = 2,
	BurningArrow = 3,
	FireworksArrow = 4,
	TormentProjectile = 5,
	ThunderingArrow = 6,
	HeavyHarpoon = 7,
	MeleeWeapon = 8,
	RangedWeapon = 9,
	Armor = 10,
	Currency = 11,
	Item = 12,
	Food = 13,
	Last = 14
};

UENUM(BlueprintType) // Enum Dungeons.EKeybindDefaultConfig
enum class EKeybindDefaultConfig : uint8
{
	Keyboard1 = 0,
	Gamepad1 = 1,
	JoyconL1 = 2,
	JoyconR1 = 3
};


UENUM(BlueprintType) // Enum Dungeons.EKeybindPlatform
enum class EKeybindPlatform : uint8
{
	KeyboardMouse = 0,
	Gamepad = 1,
	JoyconL = 2,
	JoyconR = 3
};


UENUM(BlueprintType) // Enum Dungeons.EItemRarityChanceCategory
enum class EItemRarityChanceCategory : uint8
{
	Mob = 0,
	Boss = 1,
	WoodenChest = 2,
	FancyChest = 3,
	DeluxeChest = 4,
	LobbyChest = 5,
	MissionEnd = 6,
	PiggyBank = 7,
	ProgressCommand = 8,
	Default = 9,
	EnchantedMobGroup = 10,
	EventMob = 11,
	VillageMerchant = 12,
	LuxuryMerchant = 13,
	PiglinMerchant = 14,
	MysteryBox = 15,
	OnlyCommon = 16,
	AncientMob = 17
};


UENUM(BlueprintType) // Enum Dungeons.ECharacterLoadoutType
enum class ECharacterLoadoutType : uint8
{
	DefaultLoadout = 0,
	TutorialLoadout = 1
};


UENUM(BlueprintType) // Enum Dungeons.ELobbyNames
enum class ELobbyNames : uint8
{
	Invalid = 0,
	lobby = 1
};


UENUM(BlueprintType) // Enum Dungeons.ELevelVariationType
enum class ELevelVariationType : uint8
{
	Invalid = 0,
	none = 1,
	daily = 2,
	weekly = 3,
	seasonal = 4
};


UENUM(BlueprintType) // Enum Dungeons.ELoadingState
enum class ELoadingState : uint8
{
	Idle = 0,
	Loading = 1,
	TearingDown = 2
};


UENUM(BlueprintType) // Enum Dungeons.DungeonsLocale
enum class EDungeonsLocale : uint8
{
	en = 0,
	deDE = 1,
	frFR = 2,
	esES = 3,
	enUK = 4,
	esMX = 5,
	itIT = 6,
	jaJP = 7,
	koKR = 8,
	plPL = 9,
	ptPT = 10,
	ptBR = 11,
	ruRU = 12,
	svSE = 13,
	zhCN = 14,
	zhTW = 15
};


UENUM(BlueprintType) // Enum Dungeons.ELootType
enum class ELootType : uint8
{
	WoodenChest = 0,
	FancyChest = 1
};


UENUM(BlueprintType) // Enum Dungeons.EMapHeightThreshold
enum class EMapHeightThreshold : uint8
{
	BelowThreshold = 0,
	WithinThreshold = 1,
	AboveThreshold = 2
};


UENUM(BlueprintType) // Enum Dungeons.EMapTextureSampler
enum class EMapTextureSampler : uint8
{
	Size1x1 = 0,
	Size2x2 = 1
};


UENUM(BlueprintType) // Enum Dungeons.EOutsideBoundBehavior
enum class EOutsideBoundBehavior : uint8
{
	RevealExplored = 0,
	RevealAlways = 1
};


UENUM(BlueprintType) // Enum Dungeons.EMapType
enum class EMapType : uint8
{
	UNSET = 0,
	Fullscreen = 1,
	Overlay = 2
};


UENUM(BlueprintType) // Enum Dungeons.EMerchantTransactionStatusReason
enum class EMerchantTransactionStatusReason : uint8
{
	UNSET = 0,
	CANT_AFFORD = 1,
	INVENTORY_FULL = 2,
	RECIPIENT_INVENTORY_FULL = 3,
	NO_SLOT_SELECTED = 4,
	SLOT_LOCKED = 5,
	SLOT_OCCUPIED = 6,
	ITEM_LOCKED = 7,
	NO_ITEM_SELECTED = 8,
	NO_INVENTORY_SLOT_SELECTED = 9,
	NO_INVENTORY_ITEM_SELECTED = 10,
	NO_REGIFTING = 11,
	NO_GIFTING_TO_SELF = 12,
	CANT_GIFT_CLONES = 13,
	NO_PLAYER_SELECTED = 14,
	ALREADY_RESERVED = 15,
	NOT_RESERVED = 16,
	NOTHING_TO_RESTOCK = 17,
	NOTHING_TO_WITHDRAW = 18,
	OFFER_AT_LEAST_ONE_ITEM = 19,
	MISSION_VOTE_IN_PROGRESS = 20,
	MISSION_DISABLED = 21,
	CANNOT_OFFER_GILDED_ITEMS = 22,
	CANNOT_OFFER_CLONED_ITEMS = 23,
	OFFERING_PROBLEM = 24,
	NOT_A_HYPERMISSION = 25,
	GIFT_ITEM = 26,
	BUY_ITEM = 27,
	COLLECT_ITEM = 28,
	UPGRADE_COLLECT_ITEM = 29,
	UPGRADE_ITEM = 30,
	RESERVE_ITEM = 31,
	UNRESERVE_ITEM = 32,
	OFFER_ITEM = 33,
	WITHDRAW_ITEM = 34,
	CONFIRM_OFFERINGS = 35,
	RESTOCK = 36
};


UENUM(BlueprintType)// Enum Dungeons.EMissionChancesType
enum class EMissionChancesType : uint8
{
	Gear = 0,
	Artifacts = 1,
	Rewards = 2,
	Ancients = 3
};


UENUM(BlueprintType) // Enum Dungeons.EMobStatus
enum class EMobStatus : uint8
{
	NotDefeated = 0,
	Defeated = 1,
	NotOwningDLC = 2
};


UENUM(BlueprintType) // Enum Dungeons.EInfoChanceIcon
enum class EInfoChanceIcon : uint8
{
	None = 0,
	Average = 1
};


UENUM(BlueprintType) // Enum Dungeons.EThreatDescriptionType
enum class EThreatDescriptionType : uint8
{
	Default = 0,
	EndlessStruggle = 1
};


UENUM(BlueprintType) // Enum Dungeons.EMissionEditor
enum class EMissionEditor : uint8
{
	Difficulty = 0,
	Offerings = 1
};


UENUM(BlueprintType) // Enum Dungeons.EMissionInterest
enum class EMissionInterest : uint8
{
	UNSET = 0,
	NEW_MISSION = 1,
	NEW_REWARD = 2,
	NEW_MERCHANT = 3,
	NEW_LOCATION = 4,
	NEW_BOSS = 5,
	PLAYABLE = 6
};


UENUM(BlueprintType) // Enum Dungeons.EAnimationState
enum class EAnimationState : uint8
{
	Empty = 0,
	Intro = 1,
	Start = 2,
	Update = 3,
	Complete = 4,
	Invalid = 5
};


UENUM(BlueprintType) // Enum Dungeons.EObjectiveDisplayMode
enum class EObjectiveDisplayMode : uint8
{
	InitLevel = 0,
	NewSubobjective = 1,
	NewMainObjective = 2
};


UENUM(BlueprintType) // Enum Dungeons.EMissionRequestType
enum class EMissionRequestType : uint8
{
	Start = 0,
	Continue = 1
};


UENUM(BlueprintType) // Enum Dungeons.EMobSpawnProperties
enum class EMobSpawnProperties : uint8
{
	Revealed = 0,
	Underling = 1,
	BlockMusicOverride = 2
};


UENUM(BlueprintType) // Enum Dungeons.EMobState2
enum class EMobState2 : uint8
{
	Idle = 0,
	Combat = 1,
	Staggered = 2,
	Fleeing = 3
};


UENUM(BlueprintType) // Enum Dungeons.EMouseCursorStates
enum class EMouseCursorStates : uint8
{
	UNSET = 0,
	Move = 1,
	MoveHeld = 2,
	Attack = 3,
	AttackHeld = 4,
	Interact = 5,
	InteractHeld = 6,
	Drag = 7,
	DragHeld = 8,
	Invisible = 9
};


UENUM(BlueprintType) // Enum Dungeons.EDungeonsMusicPriority
enum class EDungeonsMusicPriority : uint8
{
	BackgroundMusic = 0,
	SubDungeonsMusic = 1,
	LevelIntroMusic = 2,
	BossEncounterMusic = 3,
	SideQuestMusic = 4,
	EventMusic = 5,
	Top = 6
};


UENUM(BlueprintType) // Enum Dungeons.EMusicSequenceState
enum class EMusicSequenceState : uint8
{
	Intro = 0,
	Main = 1,
	Outro = 2
};


UENUM(BlueprintType) // Enum Dungeons.SessionType
enum class ESessionType : uint8
{
	CROSSPLAY = 0,
	PS4 = 1,
	UNKNOWN = 2
};


UENUM(BlueprintType) // Enum Dungeons.APlayerCharacterInternal_ELoadedType
enum class EAPlayerCharacterInternal_ELoadedType : uint8
{
	NotLoaded = 0,
	LoadedIntroReady = 1,
	LoadedHot = 2
};


UENUM(BlueprintType) // Enum Dungeons.EAliveState
enum class EAliveState : uint8
{
	Alive = 0,
	Reviving = 1,
	Down = 2,
	Dead = 3
};


UENUM(BlueprintType) // Enum Dungeons.EDodgeMode
enum class EDodgeMode : uint8
{
	Unset = 0,
	Normal = 1,
	Swim = 2
};


UENUM(BlueprintType) // Enum Dungeons.EMaterialTypeEnum
enum class EMaterialTypeEnum : uint8
{
	Air = 0,
	Dirt = 1,
	Wood = 2,
	Stone = 3,
	Metal = 4,
	Water = 5,
	Lava = 6,
	Leaves = 7,
	Plant = 8,
	ReplaceablePlant = 9,
	Sponge = 10,
	Cloth = 11,
	Bed = 12,
	Fire = 13,
	Sand = 14,
	Decoration = 15,
	Glass = 16,
	Explosive = 17,
	Ice = 18,
	PackedIce = 19,
	TopSnow = 20,
	Snow = 21,
	Cactus = 22,
	Clay = 23,
	Vegetable = 24,
	Portal = 25,
	Cake = 26,
	Web = 27,
	RedstoneWire = 28,
	Carpet = 29,
	BuildableGlass = 30,
	Slime = 31,
	Piston = 32,
	Allow = 33,
	Deny = 34,
	SlippyFloor = 35,
	SurfaceTypeTotal = 36,
	Any = 37
};


UENUM(BlueprintType) // Enum Dungeons.ECustomMoverSlot
enum class ECustomMoverSlot : uint8
{
	INVALID = 0,
	Slot1 = 1,
	Slot2 = 2,
	Slot3 = 3
};


UENUM(BlueprintType) // Enum Dungeons.ELeniencySource
enum class ELeniencySource : uint8
{
	MovementSpeed = 0,
	BaseChange = 1,
	Dodge = 2,
	CustomMover = 3
};


UENUM(BlueprintType) // Enum Dungeons.EProgressStat
enum class EProgressStat : uint8
{
	WIN_MISSIONS = 0,
	GIVE_GIFTS = 1,
	DEFEAT_ENCHANTED_MOBS = 2,
	DEFEAT_EVENT_MOBS = 3,
	WIN_MISSIONS_DEFAULT = 4,
	WIN_MISSIONS_ADVENTURE = 5,
	WIN_MISSIONS_APOCALYPSE = 6,
	WIN_MISSIONS_APOCALYPSE_PLUS = 7,
	WIN_MISSIONS_APOCALYPSE_PLUS_TIER0 = 8,
	WIN_MISSIONS_APOCALYPSE_PLUS_TIER1 = 9,
	WIN_MISSIONS_APOCALYPSE_PLUS_TIER2 = 10,
	WIN_MISSIONS_APOCALYPSE_PLUS_TIER3 = 11,
	WIN_MISSIONS_APOCALYPSE_PLUS_TIER4 = 12,
	WIN_MISSIONS_APOCALYPSE_PLUS_TIER5 = 13,
	WIN_MISSIONS_APOCALYPSE_PLUS_TIER6 = 14,
	WIN_MISSIONS_APOCALYPSE_PLUS_TIER7 = 15,
	WIN_HYPERMISSIONS = 16
};


UENUM(BlueprintType) // Enum Dungeons.EPushVolumeType
enum class EPushVolumeType : uint8
{
	None = 0,
	Wind = 1
};


UENUM(BlueprintType) // Enum Dungeons.EPitchMode
enum class EPitchMode : uint8
{
	Normal = 0,
	Parallel = 1,
	Adjust = 2,
	Random = 3,
	ParallelSpawn = 4
};


UENUM(BlueprintType) // Enum Dungeons.ERealmName
enum class ERealmName : uint8
{
	Invalid = 0,
	ArchIllagerRealm = 1,
	IslandsRealm = 2,
	OtherDimensions = 3,
	count = 4
};


UENUM(BlueprintType) // Enum Dungeons.EResourcePack
enum class EResourcePack : uint8
{
	Vanilla = 0,
	Test = 1,
	SquidCoast = 2,
	CreeperWoods = 3,
	ForestTemple = 4,
	PumpkinPastures = 5,
	AndesiteHills = 6,
	SoggySwamp = 7,
	MooncoreCaverns = 8,
	RedstoneMines = 9,
	FieryForge = 10,
	ScorchedCrags = 11,
	SandstoneWastes = 12,
	DesertTemple = 13,
	EvergreenOasis = 14,
	SlimySewers = 15,
	HighblockHalls = 16,
	ObsidianPinnacle = 17,
	CactiCanyon = 18,
	Jungle = 19,
	Mycelia = 20,
	DingyJungle = 21,
	OvergrownTemple = 22,
	BambooBluff = 23,
	FrozenFjord = 24,
	LonelyFortress = 25,
	LostSettlement = 26,
	Nether = 27,
	warpedforest = 28,
	BasaltDeltas = 29,
	WindsweptPeaks = 30,
	GaleSanctum = 31,
	EndlessRampart = 32
};


UENUM(BlueprintType) // Enum Dungeons.EDodgeDirection
enum class EDodgeDirection : uint8
{
	Invalid = 0,
	Forwards = 1,
	Backwards = 2,
	Left = 3,
	Right = 4
};


UENUM(BlueprintType) // Enum Dungeons.EAchievement
enum class EAchievement : uint8
{
	INVALID = 0,
	REVIVE = 1,
	KILL_50_MOBS = 2,
	KILL_2500_MOBS = 3,
	KILL_50_PASSIVE = 4,
	KILL_50_ENCHANTED = 5,
	LVL = 6,
	LVL01 = 7,
	LVL02 = 8,
	FANCY_CHEST = 9,
	CHEST = 10,
	EMERALD = 11,
	EMERALD01 = 12,
	EAT_200_FOOD = 13,
	COMPLETE_SQUID_COAST = 14,
	COMPLETE_CREEPER_WOODS = 15,
	COMPLETE_LEVEL_GROUP1 = 16,
	COMPLETE_LEVEL_GROUP2 = 17,
	COMPLETE_LEVEL_GROUP3 = 18,
	DEFEAT_ARCH_ILLAGER_ANY = 19,
	DEFEAT_ARCH_ILLAGER_HARD = 20,
	TNT_KILL = 21,
	FULL_ENCHANTED_GEAR_SET = 22,
	FULLY_UPGRADE_ENCHANTMENT = 23,
	BEAST_MASTER = 24,
	DEFEAT_JUNGLE_ABOMINATION_ADVENTURE = 25,
	COMPLETE_PANDA_PLATEAU = 26,
	OCELOT_ARMOUR = 27,
	COMPLETE_DINGY_JUNGLE_POTION = 28,
	DEFEAT_MOOSHROOM_MONSTROSITY_ITEMS = 29,
	DEFEAT_WRETCHED_WRAITH_ADVENTURE = 30,
	COMPLETE_LOST_SETTLEMENT = 31,
	ICE_WAND_KILL = 32,
	ICE_SLIDE = 33,
	ICE_NO_WEAPONS = 34,
	COMPLETE_GALE_SANCTUM_ADVENTURE = 35,
	COMPLETE_COLOSSAL_RAMPART = 36,
	KILL_10_MOUNTAINEER_TEMPEST_KNIFE_TIMED = 37,
	UPDRAFT_WINDCALLERS = 38,
	LLAMA_OFFERING = 39,
	KILL_RAVAGER_SQUALL_GOLEM_TIMED = 40,
	DEFEAT_TEMPEST_GOLEM_PETS = 41,
	COMPLETE_OBSIDIAN_PINNACLE_APOCALYPSE5 = 42,
	COMPLETE_DAILY_TRIAL_EMERALD_ARMOUR = 43,
	DEATH_BARTER = 44,
	COMPLETE_NETHER_WASTES_APOCALYPSE = 45,
	COMPLETE_NETHER_SECRET_APOCALYPSE_PLUS = 46,
	DEFEAT_ANCIENT = 47,
	COLLECT_500_GOLD = 48,
	MERCHANTS = 49,
	GONG = 50,
	SPINWHEEL = 51,
	HYPERMISSIONS = 52,
	HOMECOMING = 53,
	EFFECTS_TRIGGER = 54,
	ENUM_END = 55
};


UENUM(BlueprintType) // Enum Dungeons.EThrowableType
enum class EThrowableType : uint8
{
	None = 0,
	TNT = 1
};


UENUM(BlueprintType) // Enum Dungeons.SubsystemType
enum class ESubsystemType : uint8
{
	Dungeons = 0,
	PS4 = 1,
	Null = 2
};


UENUM(BlueprintType) // Enum Dungeons.ESuddenDeathMode
enum class ESuddenDeathMode : uint8
{
	Always = 0,
	OnAnyPlayerDowned = 1
};


UENUM(BlueprintType) // Enum Dungeons.ETeamName
enum class ETeamName : uint8
{
	Loner = 0,
	Heroes = 1,
	Villains = 2,
	Keys = 3,
	World = 4
};


UENUM(BlueprintType) // Enum Dungeons.ETeamRelation
enum class ETeamRelation : uint8
{
	Hostile = 0,
	Neutral = 1,
	Friendly = 2
};


UENUM(BlueprintType) // Enum Dungeons.TempestArmType
enum class ETempestArmType : uint8
{
	RIGHT = 0,
	LEFT = 1,
	SHIELD = 2,
	INVALID = 3
};


UENUM(BlueprintType) // Enum Dungeons.ETargetingTickStage
enum class ETargetingTickStage : uint8
{
	HighlightingUpdate = 0,
	UpdateGamepadTargetSelection = 1,
	End = 2
};


UENUM(BlueprintType) // Enum Dungeons.EUIHintConcept
enum class EUIHintConcept : uint8
{
	Unset = 0,
	NavigationMarker = 1
};


UENUM(BlueprintType) // Enum Dungeons.EUIHintClose
enum class EUIHintClose : uint8
{
	Unset = 0,
	ItemUsed = 1,
	MeleeAttack = 2,
	RangeAttack = 3,
	EnterRegion = 4,
	NewObjective = 5,
	PickupItem = 6,
	Move = 7
};


UENUM(BlueprintType) // Enum Dungeons.EUIHintTriggerAction
enum class EUIHintTriggerAction : uint8
{
	Unset = 0,
	PickupItem = 1,
	ItemUsed = 2,
	EnterRegion = 3,
	NewObjective = 4,
	Move = 5
};


UENUM(BlueprintType) // Enum Dungeons.EPullInMode
enum class EPullInMode : uint8
{
	AccelerateWithTime = 0,
	AccelerateWithDistance = 1
};


UENUM(BlueprintType) // Enum Dungeons.ECurrencyObtainReason
enum class ECurrencyObtainReason : uint8
{
	Default = 0,
	Salvaged = 1,
	Pickup = 2
};


UENUM(BlueprintType) // Enum Dungeons.EWickedWraithWaypointType
enum class EWickedWraithWaypointType : uint8
{
	Normal = 0,
	Special = 1
};


UENUM(BlueprintType) // Enum Dungeons.ETakLayout
enum class ETakLayout : uint8
{
	multiplayer_default = 0,
	multiplayer_no_ranged = 1,
	local_default = 2,
	local_no_ranged = 3,
	tutorial_default = 4,
	tutorial_default_ranged = 5
};


UENUM(BlueprintType) // Enum Dungeons.ETeamDeathState
enum class ETeamDeathState : uint8
{
	WaitingForMissionStart = 0,
	AnyPlayerAlive = 1,
	LifeDeductedAndReviving = 2,
	GameOver = 3
};



//---------------------------------------------------------------------------
// Script Structs
//---------------------------------------------------------------------------

// ScriptStruct Dungeons.EnchantmentData
// 0x000C
USTRUCT(BlueprintType)
struct FEnchantmentData
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EEnchantmentTypeID)
		EEnchantmentTypeID                                 TypeID;                                                   // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                Level;                                                    // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EEnchantmentCategory)
		EEnchantmentCategory                               Category;                                                 // 0x0008(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EEnchantmentSource)
		EEnchantmentSource                                 Source;                                                   // 0x0009(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2];                                       // 0x000A(0x0002) MISSED OFFSET
};

// ScriptStruct Dungeons.ItemBulletPoint
// 0x0028
USTRUCT(BlueprintType)
struct FItemBulletPoint
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              Text;                                                     // 0x0000(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EBulletIcon                                        Icon;                                                     // 0x0018(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EItemTag                                           TagIcon;                                                  // 0x0019(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               Upgraded;                                                 // 0x001A(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x001B(0x0001) MISSED OFFSET
	unsigned char                                      UnknownData01[0x10];
	//struct FEnchantmentData                            Enchantment;                                              // 0x001C(0x000C) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.SerializableItemId
// 0x0014
USTRUCT(BlueprintType)
struct FSerializableItemId
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0xC];                                       // 0x0000(0x000C) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName                                       SerializedId;                                             // 0x000C(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Dungeons.PropertyColorPrio
// 0x0018
USTRUCT(BlueprintType)
struct FPropertyColorPrio
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              Prio;                                                     // 0x0000(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLinearColor                                Color;                                                    // 0x0004(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              ColorMultiplier;                                          // 0x0014(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Dungeons.Pair
// 0x0020
USTRUCT(BlueprintType)
struct FPair
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                     Key;                                                      // 0x0000(0x0010) (ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                     Value;                                                    // 0x0010(0x0010) (ZeroConstructor)
};

// ScriptStruct Dungeons.ReplicatableMap
// 0x0010
USTRUCT(BlueprintType)
struct FReplicatableMap
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FPair>                               pairs;                                                    // 0x0000(0x0010) (ZeroConstructor)
};

// ScriptStruct Dungeons.ReplicatableTrialDef
// 0x0040
USTRUCT(BlueprintType)
struct FReplicatableTrialDef
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ELevelNames)
		ELevelNames                                        Level;                                                    // 0x0000(0x0001) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EExtraChallenge)
		EExtraChallenge                                    ExtraChallenge;                                           // 0x0001(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x0002(0x0006) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FReplicatableMap                                   Modifiers;                                                // 0x0008(0x0010)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FReplicatableMap>                           rewards;                                                  // 0x0018(0x0010) (ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                            ID;                                                       // 0x0028(0x0010) (ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EMissionTheme)
		EMissionTheme                                      Theme;                                                    // 0x0038(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0039(0x0007) MISSED OFFSET
};

// ScriptStruct Dungeons.ReplicatableTrialDefPack
// 0x0018
USTRUCT(BlueprintType)
struct FReplicatableTrialDefPack
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FReplicatableTrialDef>                      trialDefs;                                                // 0x0000(0x0010) (ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               isSet;                                                    // 0x0010(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0011(0x0007) MISSED OFFSET
};

// ScriptStruct Dungeons.Pushback
// 0x0014
USTRUCT(BlueprintType)
struct FPushback
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               enablePushback;                                           // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              pushbackStrength;                                         // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              pushbackZFactor;                                          // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               useForwardDirection;                                      // 0x000C(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x000D(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              pushbackMultiplierRespectFactor;                          // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.ArmorPropertyData
// 0x0002
USTRUCT(BlueprintType)
struct FArmorPropertyData
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EArmorPropertyID)
		EArmorPropertyID                                   ID;                                                       // 0x0000(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EItemRarity                                        Rarity;                                                   // 0x0001(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.InventoryItemData
// 0x0068
USTRUCT(BlueprintType)
struct FInventoryItemData
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSerializableItemId                                ItemId;                                                   // 0x0000(0x0014) (Edit, BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              ItemPower;                                                // 0x0014(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FEnchantmentData>                           Enchantments;                                             // 0x0018(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FArmorPropertyData>                         ArmorProperties;                                          // 0x0028(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EItemRarity)
		EItemRarity                                        Rarity;                                                   // 0x0038(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               bIsUpgraded;                                              // 0x0039(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               bIsGifted;                                                // 0x003A(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1D];                                      // 0x003B(0x001D) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               bHasNetherite;                                            // 0x0058(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0059(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FEnchantmentData                                   NetheriteEnchantData;                                     // 0x005C(0x000C)
};

// ScriptStruct Dungeons.MusicSet
// 0x0018
USTRUCT(BlueprintType)
struct FMusicSet
{ //I'm not going to add properties for classes at the moment
	GENERATED_BODY()
		class USoundCue* Track;                                                    // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USoundCue* introduction;                                             // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USoundCue* Exit;                                                     // 0x0010(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.LevelAudio
// 0x0078
USTRUCT(BlueprintType)
struct FLevelAudio
{
	GENERATED_BODY()
		class USoundCue* LevelVOIntro;                                             // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USoundCue* LevelIntroMusic;                                          // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USoundCue* LevelVOOutro;                                             // 0x0010(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USoundCue* LevelBackgroundMusic;                                     // 0x0018(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USoundCue* EnvironmentSFX;                                           // 0x0020(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FMusicSet                                        LevelSideQuestBattleMusic;                                // 0x0028(0x0018) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FMusicSet                                        LevelEncounterMusic;                                      // 0x0040(0x0018) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FMusicSet                                        LevelBossMusic;                                           // 0x0058(0x0018) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UReverbEffect* MainReverb;                                               // 0x0070(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.DungeonsMusicTrack
// 0x001C
USTRUCT(BlueprintType)
struct FDungeonsMusicTrack
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x4];                                       // 0x0000(0x0004) MISSED OFFSET
	TWeakObjectPtr<class USoundCue>                    Track;                                                    // 0x0004(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x10];                                      // 0x000C(0x0010) MISSED OFFSET
};

// ScriptStruct Dungeons.DungeonsSoundFade
// 0x0028
USTRUCT(BlueprintType)
struct FDungeonsSoundFade
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x18];                                      // 0x0000(0x0018) MISSED OFFSET
	class UAudioComponent* mAudioComponent;                                          // 0x0018(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0020(0x0008) MISSED OFFSET
};

// ScriptStruct Dungeons.MobMusicItem
// 0x0010
USTRUCT(BlueprintType)
struct FMobMusicItem
{
	GENERATED_BODY()
		class AMobCharacter* mob;                                                      // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0008(0x0008) MISSED OFFSET
};

// ScriptStruct Dungeons.RangedAttackProjectileSpawnDescription
// 0x0030
USTRUCT(BlueprintType)
struct FRangedAttackProjectileSpawnDescription
{
	GENERATED_BODY()
		class UClass* Projectile;                                               // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                NumberOfProjectiles;                                      // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              DelaySeconds;                                             // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              DelaySecondsPerProjectile;                                // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              AngleSpan;                                                // 0x0014(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              AngleOffset;                                              // 0x0018(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MaxRandomizedAngleFactor;                                 // 0x001C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               NonRandomFirstArrow;                                      // 0x0020(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0021(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector                                            ProjectileOffset;                                         // 0x0024(0x000C) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Dungeons.RangedAttack
// 0x0058
USTRUCT(BlueprintType)
struct FRangedAttack
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Range;                                                    // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	class UAnimSequenceBase* Animation;                                                // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName                                              slot;                                                     // 0x0010(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FRangedAttackProjectileSpawnDescription>    ProjectileDefinition;                                     // 0x0018(0x0010) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FRangedAttackProjectileSpawnDescription>    ChargedProjectileDefinition;                              // 0x0028(0x0010) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               Interruptable;                                            // 0x0038(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0039(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              AttackRateSeconds;                                        // 0x003C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              ChargeTimeSecond;                                         // 0x0040(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              ChargeVelocityMultiplier;                                 // 0x0044(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              ChargeDamageMultiplier;                                   // 0x0048(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              ActiveCancelPorintFactor;                                 // 0x004C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              ProjectileVelocityFactor;                                 // 0x0050(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              ProjectileDamageFactor;                                   // 0x0054(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Dungeons.ProjectileSpawnData
// 0x0048
USTRUCT(BlueprintType)
struct FProjectileSpawnData
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x48];                                      // 0x0000(0x0048) MISSED OFFSET
};

// ScriptStruct Dungeons.MontageData
// 0x0048
USTRUCT(BlueprintType)
struct FMontageData
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x48];                                      // 0x0000(0x0048) MISSED OFFSET
};

// ScriptStruct Dungeons.ItemDropSource
// 0x0020
USTRUCT(BlueprintType)
struct FItemDropSource
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector                                            DropLocation;                                             // 0x0000(0x000C) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
	class AActor* SourceActor;                                              // 0x0010(0x0008) (ZeroConstructor, IsPlainOldData)
	class APlayerCharacter* TriggeringPlayer;                                         // 0x0018(0x0008) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.DropGeneratorData
// 0x0018
USTRUCT(BlueprintType)
struct FDropGeneratorData
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EDropGeneratorCategory)
		EDropGeneratorCategory                             GeneratorCategory;                                        // 0x0000(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	unsigned char                                      UnknownData01[0x10];
	//TArray<FSerializableItemId>                        DropTable;                                                // 0x0008(0x0010) (ZeroConstructor)
};

// ScriptStruct Dungeons.NetworkedItemDropData
// 0x0028
USTRUCT(BlueprintType)
struct FNetworkedItemDropData
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FDropGeneratorData                                 DropData;                                                 // 0x0000(0x0018)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EDropSpawnType)
		EDropSpawnType                                     SpawnType;                                                // 0x0018(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0019(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                MinAmount;                                                // 0x001C(0x0004) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                MaxAmount;                                                // 0x0020(0x0004) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Probability;                                              // 0x0024(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.BeamUpdaterInfo
// 0x0018
USTRUCT(BlueprintType)
struct FBeamUpdaterInfo
{
	GENERATED_BODY()
		class UParticleSystemComponent* System;                                                   // 0x0000(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int>                                        EmitterIndecies;                                          // 0x0008(0x0010) (ZeroConstructor)
};

// ScriptStruct Dungeons.VitalityThreshold
// 0x0018
USTRUCT(BlueprintType)
struct FVitalityThreshold
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              Threshold;                                                // 0x0000(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                            Name;                                                     // 0x0008(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Dungeons.MerchantPricing
// 0x0008
USTRUCT(BlueprintType)
struct FMerchantPricing
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                Price;                                                    // 0x0000(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              RebateApplied;                                            // 0x0004(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.MerchantDisplayPrice
// 0x001C
USTRUCT(BlueprintType)
struct FMerchantDisplayPrice
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FMerchantPricing                            Pricing;                                                  // 0x0000(0x0008) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FSerializableItemId                         CurrencyItemId;                                           // 0x0008(0x0014) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.ProblemStatus
// 0x0048
USTRUCT(BlueprintType)
struct FProblemStatus
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                       problem;                                                  // 0x0000(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                       remedy;                                                   // 0x0018(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                       progress;                                                 // 0x0030(0x0018) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.AnimGraphStateConditions
// 0x002C
USTRUCT(BlueprintType)
struct FAnimGraphStateConditions
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EAnimLocomotion)
		EAnimLocomotion                                    FallBackLocomotionBlend;                                  // 0x0000(0x0001) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector                                            LocomotionVelocity;                                       // 0x0004(0x000C) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              LocomotionWalkRatio;                                      // 0x0010(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              RelativeMoveSpeed;                                        // 0x0014(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              LocomotionWalkVariedPlayRate;                             // 0x0018(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector                                            LookAtPoint;                                              // 0x001C(0x000C) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              LookAtAlpha;                                              // 0x0028(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
};

// ScriptStruct Dungeons.CharacterLevel
// 0x0010
USTRUCT(BlueprintType)
struct FCharacterLevel
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                Level;                                                    // 0x0000(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                CurrentXp;                                                // 0x0004(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                lastLevelXp;                                              // 0x0008(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                nextLevelXp;                                              // 0x000C(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.RegisteredSource
// 0x0020
USTRUCT(BlueprintType)
struct FRegisteredSource
{
	GENERATED_BODY()
		class UEntitlementsRepository* Repository;                                               // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x18];                                      // 0x0008(0x0018) MISSED OFFSET
};

// ScriptStruct Dungeons.Entitlement
// 0x0038
USTRUCT(BlueprintType)
struct FEntitlement
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString                                            Name;                                                     // 0x0000(0x0010) (ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString                                            Signature;                                                // 0x0010(0x0010) (ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString                                            SigningUserId;                                            // 0x0020(0x0010) (ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EEntitlementsSource)
		EEntitlementsSource                                EntitlementsSource;                                       // 0x0030(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0031(0x0007) MISSED OFFSET
};

// ScriptStruct Dungeons.EntitledCosmetic
// 0x0040
USTRUCT(BlueprintType)
struct FEntitledCosmetic
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName                                       CosmeticId;                                               // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FEntitlement)
		FEntitlement                                Entitlement;                                              // 0x0008(0x0038)
};

// ScriptStruct Dungeons.SessionPlayerInfo
// 0x0028
USTRUCT(BlueprintType)
struct FSessionPlayerInfo
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                            GamerTag;                                                 // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                            PSNName;                                                  // 0x0010(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EPlayerPlatform                                    PLATFORM;                                                 // 0x0020(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		ESessionOnlineService                              OnlineService;                                            // 0x0021(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               ShouldShowCrossplayIcon;                                  // 0x0022(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               ShouldShowPSNIcon;                                        // 0x0023(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               IsHost;                                                   // 0x0024(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0025(0x0003) MISSED OFFSET
};

// ScriptStruct Dungeons.DamageNumberInstance
// 0x0040
USTRUCT(BlueprintType)
struct FDamageNumberInstance
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Damage;                                                   // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AActor* Target;                                                   // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector_NetQuantize10                              Location;                                                 // 0x0010(0x000C)
	unsigned char                                      UnknownData01[0x4];                                       // 0x001C(0x0004) MISSED OFFSET
	unsigned char                                      UnknownData02[0x20];
	//FGameplayTagContainer                              Tags;                                                     // 0x0020(0x0020)
};

// ScriptStruct Dungeons.WeightedMobType
// 0x0018
USTRUCT(BlueprintType)
struct FWeightedMobType
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString                                            MobType;                                                  // 0x0000(0x0010) (Edit, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Weight;                                                   // 0x0010(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
};

// ScriptStruct Dungeons.ItemDrop
// 0x0010
USTRUCT(BlueprintType)
struct FItemDrop
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EDropCategory)
		EDropCategory                                      Category;                                                 // 0x0000(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                MinAmount;                                                // 0x0004(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                MaxAmount;                                                // 0x0008(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Probability;                                              // 0x000C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.EndlessStruggle
// 0x0004
USTRUCT(BlueprintType)
struct FEndlessStruggle
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                Value;                                                    // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.EndlessStruggleConfiguration
// 0x0048
USTRUCT(BlueprintType)
struct FEndlessStruggleConfiguration
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              XPMultiplier;                                             // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              LootPowerMultiplier;                                      // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              LootQualityBoost;                                         // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              ShopPriceMultiplier;                                      // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MobCountMultiplier;                                       // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MobMaxHealthMultiplier;                                   // 0x0014(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MobPerformHealingMultiplier;                              // 0x0018(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MobMaxEnduranceMultiplier;                                // 0x001C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MobRecoverEnduranceMultiplier;                            // 0x0020(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MobDamageMultiplier;                                      // 0x0024(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MobStunDurationMultiplier;                                // 0x0028(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MobSpeedMultiplier;                                       // 0x002C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MobResurrectionChance;                                    // 0x0030(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MobPushbackMultiplier;                                    // 0x0034(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MobDeflectChance;                                         // 0x0038(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              EnchantedMobChanceMultiplier;                             // 0x003C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              EnchantedMobPowerMultiplier;                              // 0x0040(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              PlayerReceiveHealingMultiplier;                           // 0x0044(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.HandleUIDataInfo
// 0x0010
USTRUCT(BlueprintType)
struct FHandleUIDataInfo
{
	GENERATED_BODY()
		unsigned char                                 UnknownData00[0x8];
	//FActiveGameplayEffectHandle                 Handle;                                                   // 0x0000(0x0008) (BlueprintVisible, BlueprintReadOnly)
	class UGameplayEffectUIData* uiData;                                                   // 0x0008(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.BlueprintFriend
// 0x0110
USTRUCT(BlueprintType)
struct FBlueprintFriend
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                            DisplayName;                                              // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                            RealName;                                                 // 0x0010(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               IsOnline;                                                 // 0x0020(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               IsPlayingThisGame;                                        // 0x0021(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               IsInJoinableSession;                                      // 0x0022(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x5];                                       // 0x0023(0x0005) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                            InGameStatus;                                             // 0x0028(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               isPlayingOnPs4;                                           // 0x0038(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x1];                                       // 0x0039(0x0001) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EFriendOnlineService                               OnlineService;                                            // 0x003A(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0xD5];                                      // 0x003B(0x00D5) MISSED OFFSET
};

// ScriptStruct Dungeons.BlueprintPlayerInfoList
// 0x0010
USTRUCT(BlueprintType)
struct FBlueprintPlayerInfoList
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FBlueprintFriend>                          Players;                                                  // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
};

// ScriptStruct Dungeons.MissionDifficulty
// 0x0008
USTRUCT(BlueprintType)
struct FMissionDifficulty
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ELevelNames)
		ELevelNames                                        mission;                                                  // 0x0000(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EGameDifficulty)
		EGameDifficulty                                    difficulty;                                               // 0x0001(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EThreatLevel)
		EThreatLevel                                       threatLevel;                                              // 0x0002(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x0003(0x0001) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FEndlessStruggle                                   EndlessStruggle;                                          // 0x0004(0x0004) (BlueprintVisible)
};

// ScriptStruct Dungeons.MissionState
// 0x0050
USTRUCT(BlueprintType)
struct FMissionState
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FMissionDifficulty                                 MissionDifficulty;                                        // 0x0000(0x0008)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                Seed;                                                     // 0x0008(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FInventoryItemData>                         offeredItems;                                             // 0x0010(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<EDLCName>                                   ownedDLCs;                                                // 0x0020(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                offeredEnchantmentPoints;                                 // 0x0030(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                livesLost;                                                // 0x0034(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                partsDiscovered;                                          // 0x0038(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x003C(0x0004) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                            Guid;                                                     // 0x0040(0x0010) (ZeroConstructor)
};

USTRUCT(BlueprintType)
struct FLevelSettings
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EGameDifficulty difficulty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EThreatLevel threatLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FEndlessStruggle EndlessStruggle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString unrealMapName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ELevelNames levelName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString levelFilename;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Seed;
};

// ScriptStruct Dungeons.BlueprintGameSession
// 0x0190
USTRUCT(BlueprintType)
struct FBlueprintGameSession
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLevelSettings                              LevelSettings;                                            // 0x0000(0x0080) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                        IsPublic;                                                 // 0x0080(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                               UnknownData00[0xD7];                                      // 0x0081(0x00D7) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                       ReceivedStartTime;                                        // 0x0158(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                               UnknownData01[0x4];                                       // 0x015C(0x0004) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                     HostDisplayName;                                          // 0x0160(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                     InviteSenderName;                                         // 0x0170(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FBlueprintPlayerInfoList                    PlayerInfoList;                                           // 0x0180(0x0010) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.SoftBrush
// 0x0030
USTRUCT(BlueprintType)
struct FSoftBrush
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               matchSize;                                                // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	unsigned char                                      UnknownData01[0x28];                                      // 0x0001(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Dungeons.SoftBrush.Texture
};

// ScriptStruct Dungeons.EffectGroupParams
// 0x0008
USTRUCT(BlueprintType)
struct FEffectGroupParams
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              IndividualSpawnRadius;                                    // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               bSpawnAtOldPositionIfOverlap;                             // 0x0004(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               bDebugVisuals;                                            // 0x0005(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0006(0x0002) MISSED OFFSET
};

// ScriptStruct Dungeons.EffectActor
// 0x000C
USTRUCT(BlueprintType)
struct FEffectActor
{
	GENERATED_BODY()
		TWeakObjectPtr<class AReusedEffectActor>           Actor;                                                    // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0008(0x0004) MISSED OFFSET
};

// ScriptStruct Dungeons.SpawnEffects
// 0x0030
USTRUCT(BlueprintType)
struct FSpawnEffects
{
	GENERATED_BODY()
		class UParticleSystem* PreSpawnMediumParticles;                                  // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UParticleSystem* PreSpawnLargeParticles;                                   // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UParticleSystem* SpawnMediumParticles;                                     // 0x0010(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UParticleSystem* SpawnLargeParticles;                                      // 0x0018(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USoundCue* PreSpawnSound;                                            // 0x0020(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USoundCue* SpawnSound;                                               // 0x0028(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.EnchantmentDataWithRarity
// 0x0010
USTRUCT(BlueprintType)
struct FEnchantmentDataWithRarity
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FEnchantmentData)
		FEnchantmentData                                   Enchantment;                                              // 0x0000(0x000C) (Edit, BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EItemRarity)
		EItemRarity                                        Rarity;                                                   // 0x000C(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x000D(0x0003) MISSED OFFSET
};

// ScriptStruct Dungeons.TitleNews
// 0x0078
USTRUCT(BlueprintType)
struct FTitleNews
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x10];                                      // 0x0000(0x0010) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              Title;                                                    // 0x0010(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              Category;                                                 // 0x0028(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              Body;                                                     // 0x0040(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UTexture2DDynamic* HeaderImage;                                              // 0x0058(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x18];                                      // 0x0060(0x0018) MISSED OFFSET
};

// ScriptStruct Dungeons.TitleNewsMapPopup
// 0x0090
USTRUCT(BlueprintType)
struct FTitleNewsMapPopup
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x10];                                      // 0x0000(0x0010) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              Title;                                                    // 0x0010(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              Body;                                                     // 0x0028(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UTexture2DDynamic* HeaderImage;                                              // 0x0040(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UTexture2DDynamic* ThumbnailImage;                                           // 0x0048(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EMissionTheme                                      Theme;                                                    // 0x0050(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               HasCountdown;                                             // 0x0051(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x6];                                       // 0x0052(0x0006) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FDateTime                                          EndTime;                                                  // 0x0058(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	unsigned char                                      UnknownData02[0x30];                                      // 0x0060(0x0030) MISSED OFFSET
};

// ScriptStruct Dungeons.ProjectileItemSpec
// 0x0030
USTRUCT(BlueprintType)
struct FProjectileItemSpec
{
	GENERATED_BODY()
		TArray<class UClass*>                              ClassesToSpawn;                                           // 0x0000(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                AmountMin;                                                // 0x0010(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                AmountMax;                                                // 0x0014(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              VelocityMin;                                              // 0x0018(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              VelocityMax;                                              // 0x001C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              ConeAngle;                                                // 0x0020(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector                                            LaunchDirectionFromOrigin;                                // 0x0024(0x000C) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Dungeons.ProjectileElement
// 0x0050
USTRUCT(BlueprintType)
struct FProjectileElement
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform                                         SpawnTransform;                                           // 0x0000(0x0030) (IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector                                            Velocity;                                                 // 0x0030(0x000C) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x003C(0x0004) MISSED OFFSET
	class UClass* ActorTypeToSpawn;                                         // 0x0040(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0048(0x0008) MISSED OFFSET
};

// ScriptStruct Dungeons.HierarchyPlacement
// 0x0010
USTRUCT(BlueprintType)
struct FHierarchyPlacement
{
	GENERATED_BODY()
		class UClass* classType;                                                // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                placement;                                                // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Dungeons.NavigationArea
// 0x0010
USTRUCT(BlueprintType)
struct FNavigationArea
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ENavAreaType)
		ENavAreaType                                       AreaType;                                                 // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	class UClass* NavigationModifierActor;                                  // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.ObjectiveLocations
// 0x0018
USTRUCT(BlueprintType)
struct FObjectiveLocations
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FVector>                                    Locations;                                                // 0x0000(0x0010) (BlueprintVisible, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               bUseLocations;                                            // 0x0010(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0011(0x0007) MISSED OFFSET
};

// ScriptStruct Dungeons.AffectorInfo
// 0x0020
USTRUCT(BlueprintType)
struct FAffectorInfo
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              DisplayText;                                              // 0x0000(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EAffectorModus                                     Modus;                                                    // 0x0018(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0019(0x0007) MISSED OFFSET
};

// ScriptStruct Dungeons.DamageMultiplier
// 0x000C
USTRUCT(BlueprintType)
struct FDamageMultiplier
{
	GENERATED_BODY()
		unsigned char                                      UnknownData[0x8];
	//FGameplayTag                                       Tag;                                                      // 0x0000(0x0008) (Edit, BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Multiplier;                                               // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.DamageFilter
// 0x0010
USTRUCT(BlueprintType)
struct FDamageFilter
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FDamageMultiplier>                   Multipliers;                                              // 0x0000(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Dungeons.ImpactFilterEntry
// 0x000C
USTRUCT(BlueprintType)
struct FImpactFilterEntry
{
	GENERATED_BODY()
		unsigned char                                      UnknownData[0x8];
	//FGameplayTag                                       Tag;                                                      // 0x0000(0x0008) (Edit, BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               Allow;                                                    // 0x0008(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0009(0x0003) MISSED OFFSET
};

// ScriptStruct Dungeons.ImpactFilter
// 0x0010
USTRUCT(BlueprintType)
struct FImpactFilter
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FImpactFilterEntry>                         Entries;                                                  // 0x0000(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Dungeons.ContextSensitiveAction
// 0x0020
USTRUCT(BlueprintType)
struct FContextSensitiveAction
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText                                       ActionText;                                               // 0x0000(0x0018) (Edit, BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName                                       Action;                                                   // 0x0018(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.InventoryItemMetaData
// 0x0002
USTRUCT(BlueprintType)
struct FInventoryItemMetaData
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               MarkedNew;                                                // 0x0000(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               Cloned;                                                   // 0x0001(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.ItemCharacteristic
// 0x0030
USTRUCT(BlueprintType)
struct FItemCharacteristic
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              Text;                                                     // 0x0000(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EItemRarity                                        Rarity;                                                   // 0x0018(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               bIsNetherite;                                             // 0x0019(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x16];                                      // 0x001A(0x0016) MISSED OFFSET
};

// ScriptStruct Dungeons.DropCategoryDescription
// 0x001C
USTRUCT(BlueprintType)
struct FDropCategoryDescription
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EDropCategory)
		EDropCategory                                      Category;                                                 // 0x0000(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MinProbability;                                           // 0x0004(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MaxProbability;                                           // 0x0008(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                MinAmount;                                                // 0x000C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                MaxAmount;                                                // 0x0010(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              TimeToMaxSeconds;                                         // 0x0014(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               Exclusive;                                                // 0x0018(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0019(0x0003) MISSED OFFSET
};

// ScriptStruct Dungeons.ItemStatsEntry
// 0x0058
USTRUCT(BlueprintType)
struct FItemStatsEntry
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EItemStats                                         ItemStatsID;                                              // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                ScoreInt;                                                 // 0x0004(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              ScoreFloat;                                               // 0x0008(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                ScoreMax;                                                 // 0x000C(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              DisplayName;                                              // 0x0010(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              DisplayNameLow;                                           // 0x0028(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              DisplayNameHigh;                                          // 0x0040(0x0018) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.StatsWrapper
// 0x0010
USTRUCT(BlueprintType)
struct FStatsWrapper
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FItemStatsEntry>                     Stats;                                                    // 0x0000(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Dungeons.ItemSalvageInfo
// 0x0058
USTRUCT(BlueprintType)
struct FItemSalvageInfo
{
	GENERATED_BODY()
		unsigned char                                      UnknownData01[0x50];
	//TMap<FSerializableItemId, int>              currencies;                                               // 0x0000(0x0050) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                enchantmentPoints;                                        // 0x0050(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0054(0x0004) MISSED OFFSET
};

// ScriptStruct Dungeons.ItemSalvageUndoInfo
// 0x0068
USTRUCT(BlueprintType)
struct FItemSalvageUndoInfo
{
	GENERATED_BODY()
		class UInventoryItemSlot* slot;                                                     // 0x0000(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UInventoryItem* Item;                                                     // 0x0008(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FItemSalvageInfo                            salvageInfo;                                              // 0x0010(0x0058) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.MissionOfferings
// 0x0018
USTRUCT(BlueprintType)
struct FMissionOfferings
{
	GENERATED_BODY()
		TArray<class UInventoryItem*>                      offeredItems;                                             // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                offeredEnchantmentPoints;                                 // 0x0010(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
};

// ScriptStruct Dungeons.Keybinding
// 0x0028
USTRUCT(BlueprintType)
struct FKeybinding
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName                                       Name;                                                     // 0x0000(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                               UnknownData01[0x18];
	//FKey                                        Key;            // 0x0008(0x0018) (BlueprintVisible)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0020(0x0008) MISSED OFFSET
};

// ScriptStruct Dungeons.LeapZConfig
// 0x000C
USTRUCT(BlueprintType)
struct FLeapZConfig
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              offsetZ;                                                  // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              leapYaw;                                                  // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              leapAmount;                                               // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.LeapXyConfig
// 0x0018
USTRUCT(BlueprintType)
struct FLeapXyConfig
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              distanceXy;                                               // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FLeapZConfig>                        Entries;                                                  // 0x0008(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Dungeons.LevelRequest
// 0x00A0
USTRUCT(BlueprintType)
struct FLevelRequest
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                PlayerId;                                                 // 0x0000(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                            PlayerName;                                               // 0x0008(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLevelSettings                                     LevelSettings;                                            // 0x0018(0x0080) (BlueprintVisible, BlueprintReadOnly)
	class ABasePlayerState* PlayerState;                                              // 0x0098(0x0008) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.MissionDifficultyCompletion
// 0x0008
USTRUCT(BlueprintType)
struct FMissionDifficultyCompletion
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EMissionDifficultyCompletionLogic)
		EMissionDifficultyCompletionLogic                  CompletionLogic;                                          // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EGameDifficulty)
		EGameDifficulty                                    DifficultyLevel;                                          // 0x0001(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ELevelNames)
		ELevelNames                                        OptionalLevelName;                                        // 0x0002(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x0003(0x0001) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                OptionalCount;                                            // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.MobKillsCompletion
// 0x0018
USTRUCT(BlueprintType)
struct FMobKillsCompletion
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString                                            MobEntityTypeName;                                        // 0x0000(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                KillCount;                                                // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
};

// ScriptStruct Dungeons.UnlockRequirements
// 0x0080
USTRUCT(BlueprintType)
struct FUnlockRequirements
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                lootID;                                                   // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText                                              Title;                                                    // 0x0008(0x0018) (Edit, BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText			                                   Name;                                                     // 0x0020(0x0018) (Edit, BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText                                              Description;                                              // 0x0038(0x0018) (Edit, BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                playerLevel;                                              // 0x0050(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                NumberOfGems;                                             // 0x0054(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FMissionDifficultyCompletion                       CompletedLevel;                                           // 0x0058(0x0008) (Edit, BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FMobKillsCompletion                                CompletedMobKills;                                        // 0x0060(0x0018) (Edit, BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               canBeReused;                                              // 0x0078(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0079(0x0007) MISSED OFFSET
};

// ScriptStruct Dungeons.LevelHitResult
// 0x0003
USTRUCT(BlueprintType)
struct FLevelHitResult
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               isHit;                                                    // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               isLiquidHit;                                              // 0x0001(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EMaterialTypeEnum)
		EMaterialTypeEnum                                  materialType;                                             // 0x0002(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.TrackedCount
// 0x0008
USTRUCT(BlueprintType)
struct FTrackedCount
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EMapTrackingTypes)
		EMapTrackingTypes                                  TrackingType;                                             // 0x0000(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                Count;                                                    // 0x0004(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.EnchantmentTriggerSettings
// 0x0003
USTRUCT(BlueprintType)
struct FEnchantmentTriggerSettings
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               bTriggerEnchantmentsOnVariantChange;                      // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               bTriggerEnchantmentsAfterDamage;                          // 0x0001(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               bTriggerEnchantmentsOnRelease;                            // 0x0002(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.MeleeAttackComponentAttackVariant
// 0x00A0
USTRUCT(BlueprintType)
struct FMeleeAttackComponentAttackVariant
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName                                              Name;                                                     // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UAnimSequenceBase* AttackSequence;                                           // 0x0008(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName                                              slot;                                                     // 0x0010(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FPushback                                          Pushback;                                                 // 0x0018(0x0014) (Edit, BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              AttackAnimationTimeDurationSeconds;                       // 0x002C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              ConeAngleDegrees;                                         // 0x0030(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              ConeOffsetUnits;                                          // 0x0034(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MinRange;                                                 // 0x0038(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              AttackRange;                                              // 0x003C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MaxZDiff;                                                 // 0x0040(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              DamageDelaySeconds;                                       // 0x0044(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Damage;                                                   // 0x0048(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x8];
	//FGameplayTag                                       DamageType;                                               // 0x004C(0x0008) (Edit, DisableEditOnInstance)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              DamageSplashMultiplier;                                   // 0x0054(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              StunMultiplier;                                           // 0x0058(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              CooldownSeconds;                                          // 0x005C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              AttackVariantResetMultiplier;                             // 0x0060(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0064(0x0004) MISSED OFFSET
	class USoundCue* HitSoundCue;                                              // 0x0068(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UAnimMontage* DynamicMontageCache;                                      // 0x0070(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                VariantLoopAmount;                                        // 0x0078(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x007C(0x0004) MISSED OFFSET
	class UClass* VariantActiveEffect;                                      // 0x0080(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UClass* VariantChangeEffect;                                      // 0x0088(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              ContinuousDamageInterval;                                 // 0x0090(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FEnchantmentTriggerSettings                        EnchantmentTriggerSettings;                               // 0x0094(0x0003) (Edit, BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               bOverrideCancelPoint;                                     // 0x0097(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              CancelPointOverride;                                      // 0x0098(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x009C(0x0004) MISSED OFFSET
};

// ScriptStruct Dungeons.SharedPredictionContext
// 0x0010
USTRUCT(BlueprintType)
struct FSharedPredictionContext
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x10];                                      // 0x0000(0x0010) MISSED OFFSET
};

// ScriptStruct Dungeons.ItemAnnouncement
// 0x0070
USTRUCT(BlueprintType)
struct FItemAnnouncement
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EItemAnnouncementType                              Type;                                                     // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FInventoryItemData                                 ItemData;                                                 // 0x0008(0x0068) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.MissionMobChance
// 0x0008
USTRUCT(BlueprintType)
struct FMissionMobChance
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
};

// ScriptStruct Dungeons.MissionProbability
// 0x0038
USTRUCT(BlueprintType)
struct FMissionProbability
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EInfoChanceIcon                                    Icon;                                                     // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              Display;                                                  // 0x0008(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              Tooltip;                                                  // 0x0020(0x0018) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.MissionItemTypeChance
// 0x0018
USTRUCT(BlueprintType)
struct FMissionItemTypeChance
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FSerializableItemId                                ItemId;                                                   // 0x0000(0x0014) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EItemRarity                                        guaranteedRarity;                                         // 0x0014(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0015(0x0003) MISSED OFFSET
};

// ScriptStruct Dungeons.MissionItemTagChance
// 0x0002
USTRUCT(BlueprintType)
struct FMissionItemTagChance
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EItemTag                                           ItemTag;                                                  // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EItemRarity                                        guaranteedRarity;                                         // 0x0001(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.MissionItemRarityChance
// 0x0001
USTRUCT(BlueprintType)
struct FMissionItemRarityChance
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EItemRarity                                        guaranteedRarity;                                         // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.MissionChances
// 0x0048
USTRUCT(BlueprintType)
struct FMissionChances
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EMissionChancesType                         missionChancesType;                                       // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                               UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FMissionItemTypeChance>              typeChances;                                              // 0x0008(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FMissionItemTagChance>               tagChances;                                               // 0x0018(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FMissionItemRarityChance>            rarityChances;                                            // 0x0028(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FMissionMobChance>                   mobChances;                                               // 0x0038(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Dungeons.ThreatDescription
// 0x0020
USTRUCT(BlueprintType)
struct FThreatDescription
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EThreatDescriptionType                             Type;                                                     // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              Text;                                                     // 0x0008(0x0018) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.DifficultyRecommendation
// 0x000C
USTRUCT(BlueprintType)
struct FDifficultyRecommendation
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EGameDifficulty                                    RecommendedDifficulty;                                    // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EThreatLevel                                       RecommendedThreatLevel;                                   // 0x0001(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EExtraChallenge                                    RecommendedExtraChallenge;                                // 0x0002(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x0003(0x0001) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FEndlessStruggle                                   RecommendedEndlessStruggle;                               // 0x0004(0x0004) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                GearPowerDistance;                                        // 0x0008(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.MissionInterestCarousel
// 0x0018
USTRUCT(BlueprintType)
struct FMissionInterestCarousel
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EMissionInterest)
		EMissionInterest                                   interestType;                                             // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<ELevelNames>                                missions;                                                 // 0x0008(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Dungeons.MissionPresentation
// 0x0020
USTRUCT(BlueprintType)
struct FMissionPresentation
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EEventType                                         EventType;                                                // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              UICountdown;                                              // 0x0004(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                ObjectiveIndex;                                           // 0x0008(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               TriggerMusicEvents;                                       // 0x000C(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x000D(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                            ID;                                                       // 0x0010(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
};

// ScriptStruct Dungeons.MapUIState
// 0x000C
USTRUCT(BlueprintType)
struct FMapUIState
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ERealmName)
		ERealmName                                         selectedRealm;                                            // 0x0000(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EGameDifficulty)
		EGameDifficulty                                    selectedDifficulty;                                       // 0x0001(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ELevelNames)
		ELevelNames                                        selectedMission;                                          // 0x0002(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EThreatLevel)
		EThreatLevel                                       selectedThreatLevel;                                      // 0x0003(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector2D                                          panPosition;                                              // 0x0004(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.MissionRequest
// 0x0058
USTRUCT(BlueprintType)
struct FMissionRequest
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EMissionRequestType                                requestType;                                              // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FMissionState                                      State;                                                    // 0x0008(0x0050) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.StartMissionStatus
// 0x0070
USTRUCT(BlueprintType)
struct FStartMissionStatus
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x70];                                      // 0x0000(0x0070) MISSED OFFSET
};

// ScriptStruct Dungeons.MissionSelection
// 0x0008
USTRUCT(BlueprintType)
struct FMissionSelection
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ELevelNames)
		ELevelNames                                        levelName;                                                // 0x0000(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EGameDifficulty)
		EGameDifficulty                                    difficulty;                                               // 0x0001(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EThreatLevel)
		EThreatLevel                                       threatLevel;                                              // 0x0002(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x0003(0x0001) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FEndlessStruggle                                   EndlessStruggle;                                          // 0x0004(0x0004) (BlueprintVisible)
};

// ScriptStruct Dungeons.MissionRequirement
// 0x0020
USTRUCT(BlueprintType)
struct FMissionRequirement
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               Completed;                                                // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              Description;                                              // 0x0008(0x0018) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.MissionProgress
// 0x0008
USTRUCT(BlueprintType)
struct FMissionProgress
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		ELevelNames                                        levelName;                                                // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EGameDifficulty                                    completedDifficulty;                                      // 0x0001(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EThreatLevel                                       completedThreatLevel;                                     // 0x0002(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x0003(0x0001) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FEndlessStruggle                                   completedEndlessStruggle;                                 // 0x0004(0x0004) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.MissionDetails
// 0x0070
USTRUCT(BlueprintType)
struct FMissionDetails
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EObjectiveDisplayMode)
		EObjectiveDisplayMode                              DisplayMode;                                              // 0x0000(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText                                              Name;                                                     // 0x0008(0x0018) (BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText                                              Description;                                              // 0x0020(0x0018) (BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                Count;                                                    // 0x0038(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                CountMax;                                                 // 0x003C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EAnimationState                                    AnimationState;                                           // 0x0040(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EEventType                                         EventType;                                                // 0x0041(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2E];                                      // 0x0042(0x002E) MISSED OFFSET
};

// ScriptStruct Dungeons.ObjectiveEventLocation
// 0x0010
USTRUCT(BlueprintType)
struct FObjectiveEventLocation
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector                                            Location;                                                 // 0x0000(0x000C) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EEventType)
		EEventType                                         EventType;                                                // 0x000C(0x0001) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               bIsSet;                                                   // 0x000D(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x000E(0x0002) MISSED OFFSET
};

// ScriptStruct Dungeons.AwardStruct
// 0x0048
USTRUCT(BlueprintType)
struct FAwardStruct
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                            Name;                                                     // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              PlayerLocalDisplayText;                                   // 0x0010(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                playerNumber;                                             // 0x0028(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                PlayerXp;                                                 // 0x002C(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FColor                                             PlayerColor;                                              // 0x0030(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName                                              PlayerSkinId;                                             // 0x0034(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                Score;                                                    // 0x003C(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EAwardType                                         Type;                                                     // 0x0040(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               IsMe;                                                     // 0x0041(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x0042(0x0006) MISSED OFFSET
};

// ScriptStruct Dungeons.GameStatsStruct
// 0x0050
USTRUCT(BlueprintType)
struct FGameStatsStruct
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              Name;                                                     // 0x0000(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                            ID;                                                       // 0x0018(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                Count;                                                    // 0x0028(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int                                                Total;                                                    // 0x002C(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               HasPercentage;                                            // 0x0030(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0031(0x0007) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                              Percentage;                                               // 0x0038(0x0018) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.MissionFinishedSummary
// 0x00B0
USTRUCT(BlueprintType)
struct FMissionFinishedSummary
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLevelSettings                                     LevelSettings;                                            // 0x0000(0x0080) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FAwardStruct>                        awards;                                                   // 0x0080(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FGameStatsStruct>                    gameStats;                                                // 0x0090(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString                                     trialIdOrBlank;                                           // 0x00A0(0x0010) (ZeroConstructor)
};

// ScriptStruct Dungeons.MobAnimationsData
// 0x0068
USTRUCT(BlueprintType)
struct FMobAnimationsData
{
	GENERATED_BODY()
		class UAnimSequenceBase* BasicAttack;                                              // 0x0000(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UAnimSequenceBase* GetHitFront;                                              // 0x0008(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UAnimSequenceBase* GetHitLeft;                                               // 0x0010(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UAnimSequenceBase* GetHitRight;                                              // 0x0018(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UAnimSequenceBase* Idle;                                                     // 0x0020(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UAnimSequenceBase* Novelty;                                                  // 0x0028(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UAnimSequenceBase* StrongAttack;                                             // 0x0030(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UAnimSequenceBase* Walk;                                                     // 0x0038(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UAnimSequenceBase* Alerted;                                                  // 0x0040(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UAnimSequenceBase* TeleportIn;                                               // 0x0048(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UAnimSequenceBase* TeleportOut;                                              // 0x0050(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName                                          TeleportSlot;                                             // 0x0058(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UAnimSequenceBase* Stunned;                                                  // 0x0060(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.MobToMash
// 0x0010
USTRUCT(BlueprintType)
struct FMobToMash
{
	GENERATED_BODY()
		class ABaseCharacter* mob;                                                      // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0008(0x0008) MISSED OFFSET
};

// ScriptStruct Dungeons.DungeonsMusicSet
// 0x0050
USTRUCT(BlueprintType)
struct FDungeonsMusicSet
{
	GENERATED_BODY()
		TMap<EMusicSequenceState, class USoundCue*>        MusicSet;                                                 // 0x0000(0x0050) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Dungeons.ObjectiveIndicatorIcon
// 0x0010
USTRUCT(BlueprintType)
struct FObjectiveIndicatorIcon
{
	GENERATED_BODY()
		class UTexture2D* tex;                                                      // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0008(0x0008) MISSED OFFSET
};

// ScriptStruct Dungeons.ObjectiveIndicator
// 0x0048
USTRUCT(BlueprintType)
struct FObjectiveIndicator
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector2D                                          Bounds;                                                   // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x40];                                      // 0x0008(0x0040) MISSED OFFSET
};

// ScriptStruct Dungeons.ItemPickupData
// 0x0018
USTRUCT(BlueprintType)
struct FItemPickupData
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSerializableItemId                                ID;                                                       // 0x0000(0x0014)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                Count;                                                    // 0x0014(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.EntitledSkin
// 0x0040
USTRUCT(BlueprintType)
struct FEntitledSkin
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName                                       SkinId;                                                   // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FEntitlement                                Entitlement;                                              // 0x0008(0x0038)
};

// ScriptStruct Dungeons.AvatarData
// 0x0010
USTRUCT(BlueprintType)
struct FAvatarData
{
	GENERATED_BODY()
		class UMaterialInstance* PortraitMaterial;                                         // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FColor                                      PlayerColor;                                              // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FColor                                      FrameBackgroundColor;                                     // 0x000C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.DodgeAnimationDirection
// 0x0068
USTRUCT(BlueprintType)
struct FDodgeAnimationDirection
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FPushback                                          Pushback;                                                 // 0x0000(0x0014) (Edit, DisableEditOnInstance)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
	TMap<EDodgeDirection, class UAnimSequenceBase*>    DodgeAnimations;                                          // 0x0018(0x0050) (Edit, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Dungeons.ProjectileCachedClass
// 0x0018
USTRUCT(BlueprintType)
struct FProjectileCachedClass
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                MinimumCachedCount;                                       // 0x0000(0x0004) (Edit, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                MaximumCachedCount;                                       // 0x0004(0x0004) (Edit, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData)
	unsigned char                                      UnknownData00[0x10];                                      // 0x0008(0x0010) MISSED OFFSET
};

// ScriptStruct Dungeons.ProjectileSpawnDefinition
// 0x0018
USTRUCT(BlueprintType)
struct FProjectileSpawnDefinition
{
	GENERATED_BODY()
		class UClass* Projectile;                                               // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                NumberOfProjectiles;                                      // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              DelaySecondsPerProjectile;                                // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              AngleSpan;                                                // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
};

// ScriptStruct Dungeons.PushVolumeInfluenceInstance
// 0x0020
USTRUCT(BlueprintType)
struct FPushVolumeInfluenceInstance
{
	GENERATED_BODY()
		class AActor* PushVolumeActor;                                          // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	class UPrimitiveComponent* InfluencedComponent;                                      // 0x0008(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector                                       PushVolumeVelocity;                                       // 0x0010(0x000C) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x001C(0x0004) MISSED OFFSET
};

// ScriptStruct Dungeons.MobChoice
// 0x0008
USTRUCT(BlueprintType)
struct FMobChoice
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EntityType                                         MobType;                                                  // 0x0000(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0000(0x0003) FIX WRONG TYPE SIZE OF PREVIOUS PROPERTY
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Weight;                                                   // 0x0004(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Dungeons.AnimNotifyStateData
// 0x0018
USTRUCT(BlueprintType)
struct FAnimNotifyStateData
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString                                            NotifyStateName;                                          // 0x0000(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	class USoundCue* TriggerSound;                                             // 0x0010(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Dungeons.SpawnElement
// 0x0030
USTRUCT(BlueprintType)
struct FSpawnElement
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               bDistanceBased;                                           // 0x0000(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MinSpawnDelay;                                            // 0x0004(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MaxSpawnDelay;                                            // 0x0008(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MinSpawnDistance;                                         // 0x000C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              MaxSpawnDistance;                                         // 0x0010(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              SpawnOffsetMin;                                           // 0x0014(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              SpawnOffsetMax;                                           // 0x0018(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               bRandomizeRotation;                                       // 0x001C(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               bSpawnOnGround;                                           // 0x001D(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2];                                       // 0x001E(0x0002) MISSED OFFSET
	TArray<class UClass*>                              Classes;                                                  // 0x0020(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Dungeons.SpawnQueue
// 0x0018
USTRUCT(BlueprintType)
struct FSpawnQueue
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSpawnElement>                       Elements;                                                 // 0x0000(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0010(0x0008) MISSED OFFSET
};

// ScriptStruct Dungeons.VectorSpeedInfo
// 0x0008
USTRUCT(BlueprintType)
struct FVectorSpeedInfo
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              TargetSize;                                               // 0x0000(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Acceleration;                                             // 0x0004(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Dungeons.SuccessStatus
// 0x0018
USTRUCT(BlueprintType)
struct FSuccessStatus
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                       status;                                                   // 0x0000(0x0018) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.TileRotation
// 0x0008
USTRUCT(BlueprintType)
struct FTileRotation
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              DegreesUE4;                                               // 0x0000(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              DegreesJson;                                              // 0x0004(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.DialogData
// 0x0030
USTRUCT(BlueprintType)
struct FDialogData
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                       Title;                                                    // 0x0000(0x0018) (BlueprintVisible, BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText                                       Body;                                                     // 0x0018(0x0018) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Dungeons.Notification
// 0x0001
USTRUCT(BlueprintType)
struct FNotification
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ENotificationType)
		ENotificationType                                  Type;                                                     // 0x0000(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.EventNotification
// 0x0037 (0x0038 - 0x0001)
USTRUCT(BlueprintType)
struct FEventNotification : public FNotification
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EEventType)
		EEventType                                         EventType;                                                // 0x0001(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x0002(0x0006) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText                                       EventTitle;                                               // 0x0008(0x0018) (BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText                                       EventMessage;                                             // 0x0020(0x0018) (BlueprintVisible)
};

// ScriptStruct Dungeons.PlayerNotification
// 0x0017 (0x0018 - 0x0001)
USTRUCT(BlueprintType)
struct FPlayerNotification : public FNotification
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName                                       SkinId;                                                   // 0x0004(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
	class ABasePlayerState* PlayerState;                                              // 0x0010(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.SelfGearPickupNotification
// 0x0077 (0x0078 - 0x0001)
USTRUCT(BlueprintType)
struct FSelfGearPickupNotification : public FNotification
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FInventoryItemData                          ItemData;                                                 // 0x0008(0x0068) (BlueprintVisible)
	class ABasePlayerController* PlayerController;                                         // 0x0070(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.OtherGearPickupNotification
// 0x0087 (0x0088 - 0x0001)
USTRUCT(BlueprintType)
struct FOtherGearPickupNotification : public FNotification
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText                                       PlayerName;                                               // 0x0008(0x0018) (BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FInventoryItemData                          ItemData;                                                 // 0x0020(0x0068) (BlueprintVisible)
};

// ScriptStruct Dungeons.ItemMetaData
// 0x0030
USTRUCT(BlueprintType)
struct FItemMetaData
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName                                       Name;                                                     // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString                                     Description;                                              // 0x0008(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              Duration;                                                 // 0x0018(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              DefaultCooldown;                                          // 0x001C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               IsGear;                                                   // 0x0020(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0021(0x0003) MISSED OFFSET
	TWeakObjectPtr<class UTexture2D>                   Image;                                                    // 0x0024(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x002C(0x0004) MISSED OFFSET
};

// ScriptStruct Dungeons.ChestDynamicProperties
// 0x0020
USTRUCT(BlueprintType)
struct FChestDynamicProperties
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                EmeraldCost;                                              // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSerializableItemId                                RewardItemId;                                             // 0x0004(0x0014) (Edit, BlueprintVisible, DisableEditOnInstance)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ELobbyChestLootType)
		ELobbyChestLootType                                ChestLootType;                                            // 0x0018(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0019(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                EmeraldReward;                                            // 0x001C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Dungeons.SkylightSettings
// 0x0018
USTRUCT(BlueprintType)
struct FSkylightSettings
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               Vissibility;                                              // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Intensity;                                                // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FLinearColor                                       Color;                                                    // 0x0008(0x0010) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.DirectionalLightSettings
// 0x0024
USTRUCT(BlueprintType)
struct FDirectionalLightSettings
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               Visibility;                                               // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Intensity;                                                // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FLinearColor                                       Color;                                                    // 0x0008(0x0010) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator                                           Angle;                                                    // 0x0018(0x000C) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.ExponentialHeightFogSettings
// 0x0028
USTRUCT(BlueprintType)
struct FExponentialHeightFogSettings
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               Visibility;                                               // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Density;                                                  // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FLinearColor                                Color;                                                    // 0x0008(0x0010) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Falloff;                                                  // 0x0018(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector                                     Location;                                                 // 0x001C(0x000C) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.WorldLightSettings
// 0x0070
USTRUCT(BlueprintType)
struct FWorldLightSettings
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               UpdateSkylight;                                           // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSkylightSettings                                  SkylightSettings;                                         // 0x0004(0x0018) (Edit, BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               UpdateDirectionalLight;                                   // 0x001C(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x001D(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FDirectionalLightSettings                          DirectionalLightSettings;                                 // 0x0020(0x0024) (Edit, BlueprintVisible)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               UpdateFog;                                                // 0x0044(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x0045(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FExponentialHeightFogSettings                      ExponentialHeightFogSettings;                             // 0x0048(0x0028) (Edit, BlueprintVisible)
};

// ScriptStruct Dungeons.AmbienceSettings
// 0x0074
USTRUCT(BlueprintType)
struct FAmbienceSettings
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               UpdateWorldLight;                                         // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWorldLightSettings                                WorldLightSettings;                                       // 0x0004(0x0070) (Edit, BlueprintVisible)
};

// ScriptStruct Dungeons.OverlappingCharacterDelegateHandles
// 0x0050
USTRUCT(BlueprintType)
struct FOverlappingCharacterDelegateHandles
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x50];                                      // 0x0000(0x0050) MISSED OFFSET
};

// ScriptStruct Dungeons.SourceItemStack
// 0x02A0
USTRUCT(BlueprintType)
struct FSourceItemStack
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x298];                                     // 0x0000(0x0298) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                Stack;                                                    // 0x0298(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x029C(0x0004) MISSED OFFSET
};

// ScriptStruct Dungeons.AttackComponentAimData
// 0x0008
USTRUCT(BlueprintType)
struct FAttackComponentAimData
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
};

// ScriptStruct Dungeons.ChallengeRewardLocation
// 0x0010
USTRUCT(BlueprintType)
struct FChallengeRewardLocation
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                ChallengeID;                                              // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector                                            Location;                                                 // 0x0004(0x000C) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.EligibleDLC
// 0x0010
USTRUCT(BlueprintType)
struct FEligibleDLC
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<EDLCName>                                   EligibleDLC;                                              // 0x0000(0x0010) (ZeroConstructor)
};

// ScriptStruct Dungeons.ExtraChallengeStyle
// 0x00A0
USTRUCT(BlueprintType)
struct FExtraChallengeStyle
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x50];                                      // 0x0000(0x0050) UNKNOWN PROPERTY: MapProperty Dungeons.ExtraChallengeStyle.wings
	unsigned char                                      UnknownData01[0x50];                                      // 0x0050(0x0050) UNKNOWN PROPERTY: MapProperty Dungeons.ExtraChallengeStyle.icons
};

// ScriptStruct Dungeons.UseSpecfiedKeyScopedPredictionWindow
// 0x0038
USTRUCT(BlueprintType)
struct FUseSpecfiedKeyScopedPredictionWindow
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x38];                                      // 0x0000(0x0038) MISSED OFFSET
};

// ScriptStruct Dungeons.SettingValueState
// 0x000C
USTRUCT(BlueprintType)
struct FSettingValueState
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                LastConfirmedSettingValue;                                // 0x0000(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                DesiredSettingValue;                                      // 0x0004(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                               SettingChanged;                                           // 0x0008(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0009(0x0003) MISSED OFFSET
};

// ScriptStruct Dungeons.ImpactInfo
// 0x0020
USTRUCT(BlueprintType)
struct FImpactInfo
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
	class AActor* ImpactedActor;                                            // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x10];                                      // 0x0010(0x0010) MISSED OFFSET
};

// ScriptStruct Dungeons.InspectorBadgeStyle
// 0x00C8
USTRUCT(BlueprintType)
struct FInspectorBadgeStyle
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x28];                                      // 0x0000(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Dungeons.InspectorBadgeStyle.Badge
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FExtraChallengeStyle                               ExtraChallenge;                                           // 0x0028(0x00A0) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
};

// ScriptStruct Dungeons.FullWedge
// 0x000C
USTRUCT(BlueprintType)
struct FFullWedge
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Radius;                                                   // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              halfAngleRadians;                                         // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              HalfHeight;                                               // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.Wedge
// 0x000C
USTRUCT(BlueprintType)
struct FWedge
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              radiusInner;                                              // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              radiusOuter;                                              // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              halfAngleRadians;                                         // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.Capsule
// 0x0008
USTRUCT(BlueprintType)
struct FCapsule
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              Radius;                                                   // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float                                              HalfHeight;                                               // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.RareItemChance
// 0x0018
USTRUCT(BlueprintType)
struct FRareItemChance
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x18];                                      // 0x0000(0x0018) MISSED OFFSET
};

// ScriptStruct Dungeons.ItemMaterialSettings
// 0x002C
USTRUCT(BlueprintType)
struct FItemMaterialSettings
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x2C];                                      // 0x0000(0x002C) MISSED OFFSET
};

// ScriptStruct Dungeons.LoadingScreenStyle
// 0x0180
USTRUCT(BlueprintType)
struct FLoadingScreenStyle
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x28];                                      // 0x0000(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Dungeons.LoadingScreenStyle.Badge
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float                                              BadgeScale;                                               // 0x0028(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x002C(0x0004) MISSED OFFSET
	unsigned char                                      UnknownData02[0x50];                                      // 0x002C(0x0050) UNKNOWN PROPERTY: MapProperty Dungeons.LoadingScreenStyle.difficulty
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLinearColor                                DifficultyColor;                                          // 0x0080(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector2D                                   DifficultyShadowOffset;                                   // 0x0090(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLinearColor                                DifficultyShadowColor;                                    // 0x0098(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x28];                                      // 0x00A8(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Dungeons.LoadingScreenStyle.ThreatLevelFlag
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLinearColor                                ThreatLevelShadowColor;                                   // 0x00D0(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FExtraChallengeStyle                        ExtraChallenge;                                           // 0x00E0(0x00A0) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
};

// ScriptStruct Dungeons.TicketEntry
// 0x000C
USTRUCT()
struct FTicketEntry
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0xC];                                       // 0x0000(0x000C) MISSED OFFSET
};

// ScriptStruct Dungeons.MerchantItemData
// 0x0070
USTRUCT()
struct FMerchantItemData
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x70];                                      // 0x0000(0x0070) MISSED OFFSET
};

// ScriptStruct Dungeons.MerchantQuestSaveData
// 0x0010
USTRUCT()
struct FMerchantQuestSaveData
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x10];                                      // 0x0000(0x0010) MISSED OFFSET
};

// ScriptStruct Dungeons.MerchantSaveData
// 0x00B0
USTRUCT()
struct FMerchantSaveData
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0xB0];                                      // 0x0000(0x00B0) MISSED OFFSET
};

// ScriptStruct Dungeons.CountQuestState
// 0x0008
USTRUCT()
struct FCountQuestState
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
};

// ScriptStruct Dungeons.MerchantSlotSaveData
// 0x0080
USTRUCT()
struct FMerchantSlotSaveData
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x80];                                      // 0x0000(0x0080) MISSED OFFSET
};

// ScriptStruct Dungeons.MerchantPricingSaveData
// 0x0004
USTRUCT()
struct FMerchantPricingSaveData
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x4];                                       // 0x0000(0x0004) MISSED OFFSET
};

// ScriptStruct Dungeons.MerchantTransactionStatus
// 0x00C8
USTRUCT()
struct FMerchantTransactionStatus
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0xC8];                                      // 0x0000(0x00C8) MISSED OFFSET
};

// ScriptStruct Dungeons.MerchantExecuteStatus
// 0x0058
USTRUCT()
struct FMerchantExecuteStatus
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x58];                                      // 0x0000(0x0058) MISSED OFFSET
};

// ScriptStruct Dungeons.DynamicQuestState
// 0x0002
USTRUCT()
struct FDynamicQuestState
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x2];                                       // 0x0000(0x0002) MISSED OFFSET
};

// ScriptStruct Dungeons.MissionMarkerStyle
// 0x00C8
USTRUCT()
struct FMissionMarkerStyle
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x28];                                      // 0x0000(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Dungeons.MissionMarkerStyle.Backplate
	unsigned char                                      UnknownData01[0x28];                                      // 0x0028(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Dungeons.MissionMarkerStyle.Background
	unsigned char                                      UnknownData02[0x28];                                      // 0x0050(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Dungeons.MissionMarkerStyle.shadow
	unsigned char                                      UnknownData03[0x28];                                      // 0x0078(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Dungeons.MissionMarkerStyle.HighlightOutline
	unsigned char                                      UnknownData04[0x28];                                      // 0x00A0(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Dungeons.MissionMarkerStyle.Border
};

// ScriptStruct Dungeons.MissionNewsStyle
// 0x0098
USTRUCT(BlueprintType)
struct FMissionNewsStyle
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLinearColor                                BorderColor;                                              // 0x0000(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FLinearColor                                GradientColor;                                            // 0x0010(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x28];                                      // 0x0020(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Dungeons.MissionNewsStyle.PopupSound
	unsigned char                                      UnknownData01[0x28];                                      // 0x0048(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Dungeons.MissionNewsStyle.AmbienceOverride
	unsigned char                                      UnknownData02[0x28];                                      // 0x0070(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Dungeons.MissionNewsStyle.MusicOverride
};

// ScriptStruct Dungeons.EndGameContentProgress
// 0x0050
USTRUCT()
struct FEndGameContentProgress
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x50];                                      // 0x0000(0x0050) UNKNOWN PROPERTY: SetProperty Dungeons.EndGameContentProgress.alreadyAnnouncedUnlockedContent
};

// ScriptStruct Dungeons.ThreatLevelProgress
// 0x0002
USTRUCT(BlueprintType)
struct FThreatLevelProgress
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EThreatLevel                                       unlocked;                                                 // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EThreatLevel                                       announced;                                                // 0x0001(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.DifficultyProgress
// 0x0003
USTRUCT(BlueprintType)
struct FDifficultyProgress
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EGameDifficulty                                    unlocked;                                                 // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EGameDifficulty                                    announced;                                                // 0x0001(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EGameDifficulty                                    selected;                                                 // 0x0002(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.TooltipStyle
// 0x002C
USTRUCT(BlueprintType)
struct FTooltipStyle
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FLinearColor                                TextShadowColor;                                          // 0x0000(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FLinearColor                                BackgroundColor;                                          // 0x0010(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector2D                                   Offset;                                                   // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool                                               AlwaysVisible;                                            // 0x0028(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0029(0x0003) MISSED OFFSET
};

// ScriptStruct Dungeons.MissionThemeMarkerStyle
// 0x0288
USTRUCT(BlueprintType)
struct FMissionThemeMarkerStyle
{
	GENERATED_BODY()
	//	unsigned char                                 UnknownData02[0xC8];
	//unsigned char                                     UnknownData03[0xC8]
	FMissionMarkerStyle                         Button;                                                   // 0x0000(0x00C8) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	FMissionMarkerStyle                         ButtonLocked;                                             // 0x00C8(0x00C8) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FExtraChallengeStyle                        ExtraChallenge;                                           // 0x0190(0x00A0) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	unsigned char                                      UnknownData00[0x28];                                      // 0x0230(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Dungeons.MissionThemeMarkerStyle.AmbienceOverride
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FTooltipStyle                               TooltipStyle;                                             // 0x0258(0x002C) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0284(0x0004) MISSED OFFSET
};


// ScriptStruct Dungeons.MobDropGroup
// 0x0010
USTRUCT()
struct FMobDropGroup
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x10];                                      // 0x0000(0x0010) MISSED OFFSET
};

// ScriptStruct Dungeons.ArcMovementInfo
// 0x0020
USTRUCT()
struct FArcMovementInfo
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x20];                                      // 0x0000(0x0020) MISSED OFFSET
};

// ScriptStruct Dungeons.OfferingsSummary
// 0x000C
USTRUCT(BlueprintType)
struct FOfferingsSummary
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                offeredCount;                                             // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                offeredTotalPower;                                        // 0x0004(0x0004) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                offeredEnchantmentPoints;                                 // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.SettingsOptions
// 0x00C0
USTRUCT(BlueprintType)
struct FSettingsOptions
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                MasterVolume;                                             // 0x0000(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                MusicVolume;                                              // 0x0004(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                MenuMusicVolume;                                          // 0x0008(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                SFXVolume;                                                // 0x000C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                DialogueVolume;                                           // 0x0010(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                AutoMute;                                                 // 0x0014(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                TextToSpeech;                                             // 0x0018(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                Subtitles;                                                // 0x001C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                SubtitleTextSize;                                         // 0x0020(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                SubtitleBoxOpacity;                                       // 0x0024(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                ColourBlindMode;                                          // 0x0028(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                FontSize;                                                 // 0x002C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                FontNormalisation;                                        // 0x0030(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                SimplifiedMissionSelectScreen;                            // 0x0034(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                DpadMovement;                                             // 0x0038(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                XboxAdaptiveControllerMode;                               // 0x003C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                VoiceOver;                                                // 0x0040(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                NavigationSound;                                          // 0x0044(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                DisplayMode;                                              // 0x0048(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                Resolution;                                               // 0x004C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                AspectRatio;                                              // 0x0050(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                Graphics;                                                 // 0x0054(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                Particles;                                                // 0x0058(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                Brightness;                                               // 0x005C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                HUDScale;                                                 // 0x0060(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                VSync;                                                    // 0x0064(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                FPSLimit;                                                 // 0x0068(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                FPSCounter;                                               // 0x006C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                TextureDetail;                                            // 0x0070(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                AntiAliasingQuality;                                      // 0x0074(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                Bloom;                                                    // 0x0078(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                AmbientOcclusion;                                         // 0x007C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                Vibration;                                                // 0x0080(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                DeadZoneLeftStick;                                        // 0x0084(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                DeadZoneRightStick;                                       // 0x0088(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                LightBarEffects;                                          // 0x008C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                AllowInvitesFrom;                                         // 0x0090(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                TutorialHints;                                            // 0x0094(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                AutoTargeting;                                            // 0x0098(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                LanguageSelect;                                           // 0x009C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                TextChat;                                                 // 0x00A0(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                AutoPickup;                                               // 0x00A4(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                EnemyOutlineColour;                                       // 0x00A8(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                Pathfinder;                                               // 0x00AC(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                RawMouseInput;                                            // 0x00B0(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                InGameSensitivity;                                        // 0x00B4(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                InMenuSensitivity;                                        // 0x00B8(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                SmartCursorBinding;                                       // 0x00BC(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Dungeons.VectorForce
// 0x0014
USTRUCT(BlueprintType)
struct FVectorForce
{
	GENERATED_BODY()
		unsigned char                                      UnknownData00[0x14];                                      // 0x0000(0x0014) MISSED OFFSET
};

//---------------------------------------------------------------------------
// Classes
//---------------------------------------------------------------------------

// Class Dungeons.GearUtil
// 0x0010 (0x0108 - 0x00F8)
UCLASS(BlueprintType)
class UGearUtil : public UActorComponent
{
	GENERATED_BODY()
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x00F8(0x0010) MISSED OFFSET
};


// Class Dungeons.Enchantment
// 0x00F0 (0x01F8 - 0x0108)
UCLASS(BlueprintType)
class UEnchantment : public UGearUtil
{
	GENERATED_BODY()
public:
	unsigned char                                      UnknownData00[0xD0];                                      // 0x0108(0x00D0) MISSED OFFSET
	int                                                Level;                                                    // 0x01D8(0x0004) (Edit, BlueprintVisible, Net, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EEnchantmentTypeID)
		EEnchantmentTypeID                                 TypeID;                                                   // 0x01DC(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EEnchantmentSource)
		EEnchantmentSource                                 EnchantmentSource;                                        // 0x01DD(0x0001) (Edit, BlueprintVisible, Net, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EItemRarity)
		EItemRarity                                        OwnerItemRarity;                                          // 0x01DE(0x0001) (Edit, BlueprintVisible, Net, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bAlwaysTrigger;                                           // 0x01DF(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               TreatAsInherrent;                                         // 0x01E0(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x01E1(0x0007) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnCurrentCounterValueChanged;                             // 0x01E8(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int GetUpgradeCostForEnchantmentTypeLevel(UPARAM() EEnchantmentTypeID Type, UPARAM() int Level, UPARAM() bool IsNetherite) { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetNameForEnchantmentType(UPARAM() EEnchantmentTypeID Type) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetLevelEffectDescriptionForEnchantmentType(UPARAM() EEnchantmentTypeID Type, UPARAM() int Level, UPARAM() float ItemPower) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetIsRarityForEnchantmentType(UPARAM() EEnchantmentTypeID Type, UPARAM() EEnchantmentRarity Rarity) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static class UTexture2D* GetIconTextureForEnchantmentType(UPARAM() class UObject* ref, UPARAM() EEnchantmentTypeID Type) { return NULL; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static class UMaterialInstance* GetIconMaterialInstanceForEnchantmentType(UPARAM() class UObject* ref, UPARAM() EEnchantmentTypeID Type) { return NULL; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetHasTagForEnchantmentType(UPARAM() EEnchantmentTypeID Type, UPARAM() EEnchantmentTag Tag) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EEnchantmentRarity GetEnchantmentTypeRarity(UPARAM() EEnchantmentTypeID Type) { return (EEnchantmentRarity)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EEnchantmentCategory GetEnchantmentTypeCategory(UPARAM() EEnchantmentTypeID Type) { return (EEnchantmentCategory)0; };
	//UFUNCTION(BlueprintCallable, BlueprintPure) - Unsupported by blueprints
	//static TArray<FItemBulletPoint> GetDisplayBulletPointsTextForEnchantmentType(EEnchantmentTypeID Type);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetDescriptionForEnchantmentType(UPARAM() EEnchantmentTypeID Type) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetCanBeUsedByMobsForEnchantmentType(UPARAM() EEnchantmentTypeID Type) { return true; };
	UFUNCTION(BlueprintCallable)
		static void BroadcastEnchantmentTriggeredEvent() {};
};


// Class Dungeons.GameVersion
// 0x0000 (0x0028 - 0x0028)

UCLASS(BlueprintType)
class UGameVersion : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool SubPlatformCheckMatch(UPARAM() ESubPlatformType PlatformFlags)
	{
		return true;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool PlatformCheckMatch(UPARAM() EPlatformType PlatformFlags)
	{
		return true;
	}

	UFUNCTION(BlueprintCallable)
		static FString GetVersionNumber()
	{
		return FString("");
	}

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetSubPlatformMatch(UPARAM() int PlatformFlags)
	{
		return true;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static ESubPlatformType GetSubPlatformEnum()
	{
		return ESubPlatformType::BASE;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetPlatformMatch(UPARAM() int PlatformFlags)
	{
		return true;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EPlatformType GetPlatformEnum()
	{
		return EPlatformType::PC;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetConfigurationMatch(UPARAM() int ConfigFlags)
	{
		return true;
	}

	UFUNCTION(BlueprintCallable)
		static FString GetBuildNumber()
	{
		return FString("");
	}

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EConfigurationType GetBuildConfiguration()
	{
		return EConfigurationType::SHIPPING;
	}

	UFUNCTION(BlueprintCallable)
		static void DungeonsPrintText(UPARAM() UObject* WorldContextObject, UPARAM() const FText& InText, UPARAM() bool bPrintToScreen, UPARAM() const FLinearColor& TextColor, UPARAM() float Duration)
	{
		return;
	}

	UFUNCTION(BlueprintCallable)
		static void DungeonsPrintString(UPARAM() UObject* WorldContextObject, UPARAM() const FString& inString, UPARAM() bool bPrintToScreen, UPARAM() const FLinearColor& TextColor, UPARAM() float Duration)
	{
		return;
	}

	UFUNCTION(BlueprintCallable)
		static FString BuildVersion()
	{
		return FString("");
	}
};

// Class Dungeons.PlayerExperienceComponent
// 0x0068 (0x0160 - 0x00F8)
UCLASS(BlueprintType)
class UPlayerExperienceComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	struct FScriptMulticastDelegate                    OnAffectXp;                                               // 0x00F8(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnLevelUp;                                                // 0x0108(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnLevelUpWithPlayer;                                      // 0x0118(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnDisplayXpChanged;                                       // 0x0128(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	unsigned char                                      UnknownData00[0x18];                                      // 0x0138(0x0018) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                mXp;                                                      // 0x0150(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0xC];                                       // 0x0154(0x000C) MISSED OFFSET

	UFUNCTION(BlueprintCallable)
		static void ServerSetXp(UPARAM() int xp) {};
	UFUNCTION(BlueprintCallable)
		static void OnRep_XpChanged() {};
	UFUNCTION(BlueprintCallable)
		static void MulticastOnLevelUp(UPARAM() int NewLevel) {};
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static float LevelProgress() { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int CurrentXp() { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int CurrentLevel() { return 0; };
	UFUNCTION(BlueprintCallable)
		static void ClientRequestXp() {};
};

// Class Dungeons.DLCDefs
// 0x0000 (0x0028 - 0x0028)
UCLASS(BlueprintType)
class UDLCDefs : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable)
		static void OpenExternalStorePageForDlcName(UPARAM() class APlayerController* PlayerController, UPARAM() const FString& Category, UPARAM() EDLCName dlcName) {};
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetDLCUpsellTitleText(UPARAM() EDLCName dlcName) { return FText();  };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetDLCUpsellDescriptionText(UPARAM() EDLCName dlcName) { return FText();  };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<FText> GetDLCUpsellBulletPoints(UPARAM() EDLCName dlcName) { return TArray<FText>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetDLCNameText(UPARAM() EDLCName dlcName) { return FText();  };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetDLCNameReleased(UPARAM() EDLCName dlcName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetDLCLocaleRequiresLogoTranslation(UPARAM() EDLCName dlcName, UPARAM() EDungeonsLocale Locale) { return false; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static class UTexture2D* GetDLCInspectorLogoTexture(UPARAM() EDLCName dlcName) { return NULL; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static class UTexture2D* GetDLCInspectorBackgroundTexture(UPARAM() EDLCName dlcName) { return NULL; };
};

// Class Dungeons.MissionProgressComponent
// 0x0230 (0x0328 - 0x00F8)
UCLASS(BlueprintType)
class UMissionProgressComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	struct FScriptMulticastDelegate                    OnUnlockAllChanged;                                       // 0x00F8(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnMissionsCompletedChanged;                               // 0x0108(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnMissionsProgressLoaded;                                 // 0x0118(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnDifficultyUnlockedChanged;                              // 0x0128(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnThreatLevelUnlockedChanged;                             // 0x0138(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnMissionsChanged;                                        // 0x0148(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnMissionStateChanged;                                    // 0x0158(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	unsigned char                                      UnknownData00[0x1C0];                                     // 0x0168(0x01C0) MISSED OFFSET

	UFUNCTION(BlueprintCallable)
		static void UnlockBonusMissionForAllPlayers(UPARAM() class UObject* WorldContextObject, UPARAM() ELevelNames Level) {};
	UFUNCTION(BlueprintCallable)
		static void UnlockBonusMissionForAllLocalPlayers(UPARAM() class UObject* WorldContextObject, UPARAM() ELevelNames Level) {};
	UFUNCTION(BlueprintCallable)
		static void UnlockBonusMission(UPARAM() ELevelNames levelName) {};
	UFUNCTION(BlueprintCallable)
		static void SetThreatLevelAnnounced(UPARAM() EThreatLevel threatLevel) {};
	UFUNCTION(BlueprintCallable)
		static void SetMapUIState(UPARAM() const FMapUIState& MapUIState) {};
	UFUNCTION(BlueprintCallable)
		static void SetHasDisplayedCompletionNotification() {};
	UFUNCTION(BlueprintCallable)
		static void SetDifficultyAnnounced(UPARAM() EGameDifficulty difficulty) {};
	UFUNCTION(BlueprintCallable)
		static void SetContentAnnounced(UPARAM() EEndGameContentType Type) {};
	UFUNCTION(BlueprintCallable)
		static void SetCompletedMission(UPARAM() EGameDifficulty difficulty, UPARAM() EThreatLevel threatLevel, UPARAM() const FEndlessStruggle& EndlessStruggle, UPARAM() ELevelNames levelName) {};
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FStartMissionStatus QueryStartMissionStatus(UPARAM() const FMissionRequest& MissionRequest) { return FStartMissionStatus(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool QueryMissionRequestIsStartable(UPARAM() const FMissionRequest& MissionRequest) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FMissionRequest PreviewMissionSelectionRequest(UPARAM() const FMissionSelection& Selection) { return FMissionRequest(); };
	UFUNCTION(BlueprintCallable)
		static void OnDifficultySelected(UPARAM() EGameDifficulty difficulty) {};
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsUnlockedAndNotTutorial(UPARAM() EGameDifficulty difficulty, UPARAM() ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsThreatLevelUnlocked(UPARAM() EThreatLevel threatLevel) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsThreatLevelAnnounced(UPARAM() EThreatLevel threatLevel) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsRealmUnlocked(UPARAM() ERealmName Realm) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsMissionUnlocked(UPARAM() EGameDifficulty difficulty, UPARAM() ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsMissionThreatLevelValid(UPARAM() ELevelNames levelName, UPARAM() EThreatLevel threatLevel) { return true;  };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsMissionThreatLevelTooLow(UPARAM() ELevelNames levelName, UPARAM() EThreatLevel threatLevel) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsMissionThreatLevelTooHigh(UPARAM() ELevelNames levelName, UPARAM() EThreatLevel threatLevel) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsMissionRevealed(UPARAM() EGameDifficulty difficulty, UPARAM() ELevelNames levelName) { return true;  };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsMissionOfInterest(UPARAM() EMissionInterest interestType, UPARAM() EGameDifficulty difficulty, UPARAM() ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsMissionNew(UPARAM() EGameDifficulty difficulty, UPARAM() ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsMissionEndlessStruggleUnlocked(UPARAM() EGameDifficulty difficulty, UPARAM() const FEndlessStruggle& EndlessStruggle) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsMissionDone(UPARAM() EGameDifficulty difficulty, UPARAM() ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsMissionDifficultyAndThreatLevelCompleted(UPARAM() EGameDifficulty difficulty, UPARAM() EThreatLevel threatLevel, UPARAM() const FEndlessStruggle& EndlessStruggle, UPARAM() ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsMissionCompleted(UPARAM() ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsLevelUnlockedForAllLocalPlayers(UPARAM() class UObject* WorldContextObject, UPARAM() ELevelNames Level) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsDLCPlayable(UPARAM() EDLCName dlc) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsDLCOwned(UPARAM() EDLCName dlc) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsDifficultyUnlocked(UPARAM() EGameDifficulty difficulty) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsDifficultyCompleted(UPARAM() EGameDifficulty difficulty) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsDifficultyAnnounced(UPARAM() EGameDifficulty difficulty) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsAnyEndlessStruggleUnlocked(UPARAM() EGameDifficulty difficulty) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool HasNeverSelectedDifficulty() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EThreatLevel GetUnannouncedUnlockedThreatLevel() { return EThreatLevel::Threat; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EGameDifficulty GetUnannouncedUnlockedDifficulty() { return (EGameDifficulty)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<EEndGameContentType> GetUnannouncedEndGameContent() { return TArray<EEndGameContentType>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int GetTotalMissionsInDifficultyOfVariationType(UPARAM() EGameDifficulty difficulty, UPARAM() ELevelVariationType variationType) { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int GetNumCompletedMissionsAtDifficulty(UPARAM() EGameDifficulty difficulty) { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EThreatLevel GetMissionValidThreatLevel(UPARAM() ELevelNames levelName, UPARAM() EGameDifficulty difficulty, UPARAM() EThreatLevel threatLevel) { return EThreatLevel::Threat; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FEndlessStruggle GetMissionValidEndlessStruggle(UPARAM() ELevelNames levelName, UPARAM() EGameDifficulty difficulty, UPARAM() EThreatLevel threatLevel, UPARAM() const FEndlessStruggle& EndlessStruggle) { return FEndlessStruggle(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<FMissionRequirement> GetMissionUnlockRequirements(UPARAM() EGameDifficulty difficulty, UPARAM() ELevelNames levelName) { return TArray<FMissionRequirement>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EThreatLevel GetMissionThreatLevelCompleted(UPARAM() ELevelNames levelName) { return (EThreatLevel)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<ELevelNames> GetMissionNamesOfInterestInDifficulty(UPARAM() EMissionInterest HintType, UPARAM() EGameDifficulty difficulty) { return TArray<ELevelNames>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<EMissionInterest> GetMissionMarkerInterestTypes(UPARAM() EGameDifficulty difficulty, UPARAM() ELevelNames levelName) { return TArray<EMissionInterest>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<EMissionInterest> GetMissionFilteredInterestTypes(UPARAM() TArray<EMissionInterest> interestTypes, UPARAM() EGameDifficulty difficulty, UPARAM() ELevelNames levelName) { return TArray<EMissionInterest>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EGameDifficulty GetMissionDifficultyCompleted(UPARAM() ELevelNames levelName) { return (EGameDifficulty)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FMapUIState GetMapUIState() { return FMapUIState(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FEndlessStruggle GetHighestUnlockedEndlessStruggle(UPARAM() EGameDifficulty difficulty) { return FEndlessStruggle(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FEndlessStruggle GetHighestCompletedEndlessStruggle() { return FEndlessStruggle(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetHasCompletedMissionAtDifficulty(UPARAM() EGameDifficulty difficulty, UPARAM() ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int GetCompletedMissionsInDifficultyOfVariationType(UPARAM() EGameDifficulty difficulty, UPARAM() ELevelVariationType variationType) { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<FMissionProgress> GetCompletedMissions() { return TArray<FMissionProgress>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FMissionInterestCarousel GetBestMissionInterestCarouselInDifficulty(UPARAM() EGameDifficulty difficulty) { return FMissionInterestCarousel(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool DoesMissionHaveNewSecretLocations(UPARAM() EGameDifficulty difficulty, UPARAM() ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool DoesMissionHaveNewRewards(UPARAM() EGameDifficulty difficulty, UPARAM() ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool DoesMissionHaveNewCapturedMerchants(UPARAM() EGameDifficulty difficulty, UPARAM() ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int CountMissionsOfInterestInDifficulty(UPARAM() EMissionInterest HintType, UPARAM() EGameDifficulty difficulty) { return 0; };
	UFUNCTION(BlueprintCallable)
		static bool ClearMissionState(UPARAM() ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool AreAllAvailableMissionDifficultiesCompleted(UPARAM() EGameDifficulty difficulty, UPARAM() ELevelNames levelName) { return true; };
};

// Class Dungeons.MissionProgressHandler
// 0x02B0 (0x05E0 - 0x0330)
UCLASS(BlueprintType)
class AMissionProgressHandler : public AInfo
{
	GENERATED_BODY()
public:
	struct FScriptMulticastDelegate                    OnNewObjectiveStarted;                                    // 0x0330(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnObjectiveUpdated;                                       // 0x0340(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCameraPanStarted;                                       // 0x0350(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCameraPanDone;                                          // 0x0360(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool                                               IsVisible;                                                // 0x0370(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0371(0x0007) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		struct FMissionDetails                             NewMissionDetails;                                        // 0x0378(0x0070) (BlueprintVisible, BlueprintReadOnly, Net)
	unsigned char                                      UnknownData01[0xC];                                       // 0x03E8(0x000C) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                mMissionProgressCount;                                    // 0x03F4(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x1E8];                                     // 0x03F8(0x01E8) MISSED OFFSET

	static void PlayMissionEndVideo(class UMediaSource* videoSource) {};
	static void OnShowMissionVictory(float WaitDurationSeconds) {};
	static void OnRep_UpdateUI() {};
	static void OnRep_MissionUpdated() {};
	static void OnRep_MissionDetails() {};
	static void OnMissionFinished() {};
	static void OnEndVideoFinished() {};
	static void MulticastObjectiveEventLocation(const FObjectiveEventLocation& Location, float Duration) {};
	static void MulticastMissionFinished(const FMissionFinishedSummary& MissionFinishedSummary, const FLevelSettings& travelLevelSettings) {};
	static void MulticastInstantMoveToLobby(const FLevelSettings& travelLevelSettings) {};
	static void MulticastGameOver(ELevelNames Level, const FString& missionStateGuid, const FLevelSettings& travelLevelSettings) {};
	UFUNCTION(BlueprintCallable)
	static void MoveToLobby(UPARAM() const FLevelSettings& LevelSettings) {};
	UFUNCTION(BlueprintCallable)
	static void MissionCancelledTravelToLobby() {};
	UFUNCTION(BlueprintCallable,BlueprintPure)
	static int GetMissionProgressionCount() { return 0; };
	static void FinishedObjectiveTag(UPARAM() const FString& TagName) {};
};

// Class Dungeons.DLCPrimaryDataAsset
// 0x0018 (0x0048 - 0x0030)
UCLASS(BlueprintType)
class UDLCPrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EDLCName)
	EDLCName                                           dlcName;                                                  // 0x0030(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0031(0x0003) MISSED OFFSET
	unsigned char                                      bIsRuntimeLabel : 1;                                      // 0x0034(0x0001) (Edit)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0035(0x0003) MISSED OFFSET
	FPrimaryAssetRules                                 Rules;                                                    // 0x0038(0x0010) (Edit)
};

UCLASS(BlueprintType)
class UDungeonsFriendsInterface : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		static void SetPresenceStatus(UPARAM() const FString& levelName) {};
};

UCLASS(BlueprintType)
class UDungeonsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDungeonsFriendsInterface* FriendsInterface;

	UFUNCTION(BlueprintCallable)
		UDungeonsFriendsInterface* GetFriendsInterface() { return FriendsInterface; };

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsInMenu() { return true; };

	UFUNCTION(BlueprintCallable)
		static void BeginLoadingScreenWithTravel(UPARAM() const FLevelSettings& LevelSettings, UPARAM() EMapLoadType mapLoadType, UPARAM() float fadeOutTime, UPARAM() float fadeinTime, UPARAM() APlayerController* PlayerController, UPARAM() const FString& connectionString) {};
};


// ==================================================================================================================================================================
// ==================================================================================================================================================================
// |||                                                               PLAYER/CHARACTER CLASSES                                                                     |||
// ==================================================================================================================================================================
// ==================================================================================================================================================================


// Class Dungeons.BaseCharacter
// 0x02C0 (0x0A10 - 0x0750)
UCLASS(BlueprintType)
class ABaseCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	unsigned char                                      UnknownData00[0x78];                                      // 0x0750(0x0078) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnKilledOther;                                            // 0x07C8(0x0010) (ZeroConstructor, InstancedReference)
	unsigned char                                      UnknownData01[0x78];                                      // 0x07D8(0x0078) MISSED OFFSET
	class USoundCue* OnLandedSound;                                            // 0x0850(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USoundCue* OnFrozenLandedSound;                                      // 0x0858(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UDungeonsAbilitySystemComponent* AbilitySystem;                                            // 0x0860(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	class UClass* InvunlerabilityEffect;                                    // 0x0868(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x8];                                       // 0x0870(0x0008) MISSED OFFSET
	class UBaseParticleAssetsComponent* Particles;                                                // 0x0878(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               EnableOcclusionSilhouetting;                              // 0x0880(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               EnableHealthBar;                                          // 0x0881(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x56];                                      // 0x0882(0x0056) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               targetable;                                               // 0x08D8(0x0001) (Edit, BlueprintVisible, Net, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bIsBlocking;                                              // 0x08D9(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x2];                                       // 0x08DA(0x0002) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              InitialTimeToLive;                                        // 0x08DC(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ETeamName)
	ETeamName                                          TeamName;                                                 // 0x08E0(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData05[0x3];                                       // 0x08E1(0x0003) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TWeakObjectPtr<class AActor>                       LookAtActor;                                              // 0x08E4(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = EAttackState)
	EAttackState                                       AttackState;                                              // 0x08EC(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x13];                                      // 0x08ED(0x0013) MISSED OFFSET
	class UEnchantmentComponent* EnchantmentComponent;                                     // 0x0900(0x0008) (Edit, ExportObject, Net, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData07[0x30];                                      // 0x0908(0x0030) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              MaxSpeed;                                                 // 0x0938(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              AnimationWalkSpeed;                                       // 0x093C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	int16_t                                            IntendedAnimationSpeed;                                   // 0x0940(0x0002) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData08[0x6];                                       // 0x0942(0x0006) MISSED OFFSET
	TArray<TWeakObjectPtr<class USceneComponent>>      componentsDisappeared;                                    // 0x0948(0x0010) (ExportObject, ZeroConstructor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ECharacterWorldState)
	ECharacterWorldState                               WorldState;                                               // 0x0958(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData09[0xF];                                       // 0x0959(0x000F) MISSED OFFSET
	class UHealthBarComponent* HealthBarComponent;                                       // 0x0968(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UPushVolumeReactiveComponent* PushVolumeReactiveComponent;                              // 0x0970(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class USimpleMovementComponent* PushVolumeMovementComponent;                              // 0x0978(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, Transient, EditConst, InstancedReference, IsPlainOldData)
	class UBlockTriggerComponent* BlockTriggerComponent;                                    // 0x0980(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TWeakObjectPtr<class USphereComponent>             CachedNearMissComponent;                                  // 0x0988(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TWeakObjectPtr<class UMassComponent>               CachedMassComponent;                                      // 0x0990(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UClass* FrozenSolidIceCubeActor;                                  // 0x0998(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData10[0x34];                                      // 0x09A0(0x0034) MISSED OFFSET
	TWeakObjectPtr<class ABaseCharacter>               Master;                                                   // 0x09D4(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData11[0x34];                                      // 0x09DC(0x0034) MISSED OFFSET

	UFUNCTION(BlueprintCallable)
		static void UpdatePushVolumeMovement(const struct FVector& pushForce) {};
	UFUNCTION(BlueprintCallable)
	static void SpawnEffectsAtLocation(class UParticleSystem* Emitter, class USoundCue* Sound, bool attached) {};
	UFUNCTION(BlueprintCallable)
	static void SpawnAttachedParticles(class UParticleSystem* particle, const struct FVector& Offset, float Duration, bool FadeOut) {};
	UFUNCTION(BlueprintCallable)
	static void SetPushImmunity(bool bEnable) {};
	UFUNCTION(BlueprintCallable)
	static void SetModifierSurface(EMaterialTypeEnum surface) {};
	UFUNCTION(BlueprintCallable)
	static void SetAttackState(EAttackState NewState) {};
	UFUNCTION(BlueprintCallable)
	static void ServerRemoveInvulnerability() {};
	UFUNCTION(BlueprintCallable)
	static void ServerApplyInvulnerability(float Duration) {};
	static void OnRep_WorldState(ECharacterWorldState previousWorldState) {};
	static void OnRep_Master() {};
	static void OnRep_LookAtActor() {};
	static void OnRep_AttackState() {};
	static void OnCharacterRevive() {};
	UFUNCTION(BlueprintCallable)
	static void OnCharacterHeal(float Amount) {};
	UFUNCTION(BlueprintCallable)
	static void OnCharacterDeath() {};
	//static void OnCharacterDamageReceivedWithType(float Amount, const FGameplayAttribute& Type) {}; //FGameplayAttribute issues
	UFUNCTION(BlueprintCallable)
	static void OnCharacterDamageReceived(float Amount) {};
	//FPredictionKey Issues
	//static void MulticastStopSlotAnimation(const FName& SlotName, float BlendOutTime, const FPredictionKey& PredictionKey) {};
	//static void MulticastStopMontage(float InBlendOutTime, class UAnimMontage* Montage, const FPredictionKey& PredictionKey) {};
	//static void MulticastStopAnimation(float InBlendOutTime, class UAnimSequenceBase* Asset, const FName& SlotNodeName, const FPredictionKey& PredictionKey) {};
	//static void MulticastSetPlayrateMontage(class UAnimMontage* Montage, float NewPlayRate, const FPredictionKey& PredictionKey) {};
	//static void MulticastResumeMontage(class UAnimMontage* Montage, const FPredictionKey& PredictionKey) {};
	//static void MulticastPlayMontageSectionWithBlendAtSectionPercentagePacked(const struct FMontageData& Data) {};
	//static void MulticastPlayMontagePacked(const struct FMontageData& Data) {};
	//static void MulticastPlayMeleeAttackVariantAnimation(unsigned char Index, float animationPlayRate, const FPredictionKey& Key) {};
	//static void MulticastPlayAnimationAsDynamicMontagePacked(const struct FMontageData& Data) {};
	//static void MulticastPauseMontage(class UAnimMontage* Montage, const FPredictionKey& PredictionKey) {};
	//static void MulticastJumpToSectionMontageWithPlayratePacked(const struct FMontageData& Data) {};
	//static void MulticastJumpToSectionMontage(const FName& SectionName, class UAnimMontage* Montage, const FPredictionKey& PredictionKey) {};
	UFUNCTION(BlueprintCallable)
	static void Kill() {};
	UFUNCTION(BlueprintCallable,BlueprintPure)
	static bool IsTargetable() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool IsHostileTowards(class ABaseCharacter* Target) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool IsFrozenSolid() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool IsFriendlyTowards(class ABaseCharacter* Target) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool IsBlocking() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static EMaterialTypeEnum GetStepMaterial() { return (EMaterialTypeEnum)0; };
	//UPushVolumeReactiveComponent issues
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//static class UPushVolumeReactiveComponent* GetPushVolumeReactiveComponent() { return NULL; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static EMaterialTypeEnum GetOverlapMaterial() { return (EMaterialTypeEnum)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static class ABaseCharacter* GetMaster() { return NULL; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static EAttackState GetAttackState() { return (EAttackState)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool CanHealTarget(class ABaseCharacter* Target) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool CanDamageTarget(class ABaseCharacter* Target) { return true; };
};


// Class Dungeons.PlayerCharacterSaveSlot
// 0x0040 (0x0A50 - 0x0A10)
UCLASS(BlueprintType)
class APlayerCharacterSaveSlot : public ABaseCharacter
{
	GENERATED_BODY()
public:
	struct FScriptMulticastDelegate                    OnSaveSlotDataChanged;                                    // 0x0A10(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	//class UItemStashComponent* ItemStashComponent;                                       // 0x0A20(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	//class UEquipmentComponent* EquipmentComponent;                                       // 0x0A28(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	//class UPlayerAvatarComponent* PlayerAvatarComponent;                                    // 0x0A30(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	//class UCosmeticsComponent* CosmeticsComponent;                                       // 0x0A38(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	//class UCharacterSerializeComponent* CharacterSerializeComponent;                              // 0x0A40(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0A48(0x0008) MISSED OFFSET

	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//	static class UPlayerAvatarComponent* GetPlayerAvatarComponent() { return NULL; };
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//	static class UItemStashComponent* GetItemStashComponent() { return NULL; };
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//	static class UEquipmentComponent* GetEquipmentComponent() { return NULL; };
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//	static struct FDateTime GetDateTime() { return FDateTime(); };
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//	static class UCosmeticsComponent* GetCosmeticsComponent() { return NULL; };
	UFUNCTION(BlueprintCallable)
		static void ChangeSkinId(const FName& SkinId) {};
	UFUNCTION(BlueprintCallable)
		static void ChangeName(const FString& Name) {};
};


// Class Dungeons.PlayerControllerBase
// 0x0090 (0x0708 - 0x0678)
UCLASS(BlueprintType)
class APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
public:
	struct FScriptMulticastDelegate                    OnSkinEverSelectedChanged;                                // 0x0678(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnRecentSaveDataIndexChanged;                             // 0x0688(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnSaveDataChanged;                                        // 0x0698(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnToggleHUDUI;                                            // 0x06A8(0x0010) (ZeroConstructor, InstancedReference)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               EnableDebugUIControls;                                    // 0x06B8(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x06B9(0x0007) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnNoSaveDataFound;                                        // 0x06C0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UCharacterSerializeComponent* mCharacterSerializeComponent;                             // 0x06D0(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x1];                                       // 0x06D8(0x0001) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bGamepadActive;                                           // 0x06D9(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0xE];                                       // 0x06DA(0x000E) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                              mLocalPlayerDisplayText;                                  // 0x06E8(0x0018)
	unsigned char                                      UnknownData03[0x8];                                       // 0x0700(0x0008) MISSED OFFSET

	UFUNCTION(BlueprintCallable)
		static void SetCoopGamepadLightColourIndex(int Index) {};
	UFUNCTION(BlueprintCallable)
		static void SaveCharacterData() {};
	UFUNCTION(BlueprintCallable)
		static void OnSelectedSkinId(const FName& SkinId) {};
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsOwnedByInitialLocalPlayer() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsInitialized() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool HasSaveData() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool HasEverSelectedSkinId(const FName& SkinId) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int GetSaveLocalUserNum() { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int GetRecentSaveDataIndex() { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int GetNumProfiles() { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetLocalPlayerDisplayText() { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetIsCharacterSlotIndexSelectable(int Index) { return true; };
	//void GetInputAnalogStickStateRadialDeadzone(TEnumAsByte<EControllerAnalogStick> WhichStick, float* StickX, float* StickY);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetGamepadActive() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int GetFirstAvailableSaveIndex() { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static class APlayerCharacterSaveSlot* GetCharacterSlotByIndex(int Index, bool forceRefreshSlot) { return NULL; };
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//	static class UCharacterSaveData* GetAvailableSaveDataByIndex(int Index) { return NULL; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool DeleteCharacterByIndex(int inIndex) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool CreateNewCharacter() { return true; };
	UFUNCTION(BlueprintCallable)
		static void ControllerTypeChanged() {};
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool CloneCharacter(int inIndex) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool CanDeleteCharacterByIndex(int inIndex) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool CanCreateNewCharacter() { return true; };
	//UFUNCTION(BlueprintCallable)
	//	static void AssignSaveData(class UCharacterSaveData* savedata) {};
};


// Class Dungeons.BasePlayerController
// 0x0710 (0x0E18 - 0x0708)
UCLASS(BlueprintType)
class ABasePlayerController : public APlayerControllerBase
{
	GENERATED_BODY()
public:
	struct FScriptMulticastDelegate                    OnServerLogout;                                           // 0x0708(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	unsigned char                                      UnknownData00[0x30];                                      // 0x0718(0x0030) MISSED OFFSET
	struct FScriptMulticastDelegate                    ReceiveOnAnyPlayerAction;                                 // 0x0748(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTriggerPopup;                                           // 0x0758(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTriggerPopupGlobal;                                     // 0x0768(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTriggerAchivement;                                      // 0x0778(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	unsigned char                                      UnknownData01[0x30];                                      // 0x0788(0x0030) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnPlayerTeleportButton;                                   // 0x07B8(0x0010) (ZeroConstructor, InstancedReference)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              mLastMouseX;                                              // 0x07C8(0x0004) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              mLastMouseY;                                              // 0x07CC(0x0004) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              mLastMoveX;                                               // 0x07D0(0x0004) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              mLastMoveY;                                               // 0x07D4(0x0004) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              mLastRollX;                                               // 0x07D8(0x0004) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              mLastRollY;                                               // 0x07DC(0x0004) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              mTargetCameraFOV;                                         // 0x07E0(0x0004) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              mCurrentCameraFOV;                                        // 0x07E4(0x0004) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               RightStickDodgingEnabled;                                 // 0x07E8(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               RightStickHasReset;                                       // 0x07E9(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bIsUIInputAllowed;                                        // 0x07EA(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x1D];                                      // 0x07EB(0x001D) MISSED OFFSET
	class UClass* DefaultNavigationFilterClass;                             // 0x0808(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class AActor* SecondaryHighlightTarget;                                 // 0x0810(0x0008) (ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              AttackTargetRetargetingWindowSeconds;                     // 0x0818(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x081C(0x0004) MISSED OFFSET
	//class UPlayerPathFollowingComponent* PathFollowingComponent;                                   // 0x0820(0x0008) (Edit, ExportObject, ZeroConstructor, DisableEditOnInstance, EditConst, InstancedReference, IsPlainOldData)
	struct FScriptMulticastDelegate                    OnDestructibleComponentDestroyed;                         // 0x0828(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float                                              ClickyCollisionRadiusTargetLimit;                         // 0x0838(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              TargetReacquisitionTimeoutSeconds;                        // 0x083C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               DestructibleDebugVisuals;                                 // 0x0840(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               EnableDebug;                                              // 0x0841(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x127];                                     // 0x0842(0x0127) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               IsHostingPlayer;                                          // 0x0969(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x76];                                      // 0x096A(0x0076) MISSED OFFSET
	class AAutoTarget* mAutoTarget;                                              // 0x09E0(0x0008) (ZeroConstructor, IsPlainOldData)
	class UObjectDistanceNotifier* PlayerDistanceNotifier;                                   // 0x09E8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x40];                                      // 0x09F0(0x0040) MISSED OFFSET
	TArray<class AMobCharacter*>                       LastSecondaryTargets;                                     // 0x0A30(0x0010) (ZeroConstructor)
	class AMobCharacter* CurrentSecondaryTarget;                                   // 0x0A40(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData07[0x3D0];                                     // 0x0A48(0x03D0) MISSED OFFSET

	UFUNCTION(BlueprintCallable)
		static void UpdateInitialBlueprintSetup() {};
	UFUNCTION(BlueprintCallable)
	static void ShowDebugInfo(bool ShowDebug) {};
	UFUNCTION(BlueprintCallable)
		static void SetWantsToActivateSlot(ESlotType Type, int Index, bool wantsToActivate) {};
	UFUNCTION(BlueprintCallable)
		static void SetTeleportListOpen(bool ListOpen) {};
	UFUNCTION(BlueprintCallable)
		static void SetPlayerIsImmovable(bool immovable) {};
	UFUNCTION(BlueprintCallable)
		static void SetInputCapturedByUI(bool Captured, bool CaptureLocalPlayers) {};
	UFUNCTION(BlueprintCallable)
		static void ServerSetNetConnectionSpeed(int NewNetSpeed) {};
	UFUNCTION(BlueprintCallable)
		static void ServerRequestMoveEveryoneToLobby() {};
	UFUNCTION(BlueprintCallable)
		static void ServerRequestAwards() {};
	//UFUNCTION(BlueprintCallable)
	//	static void ServerInteract(class UReplicatedInteractableComponent* interactable, class AActor* interactor) {};
	UFUNCTION(BlueprintCallable)
		static void Server_DeferredConsoleCommand(const FString& Command) {};
	UFUNCTION(BlueprintCallable)
		static void ResetMouseCursorToLastPosition() {};
	UFUNCTION(BlueprintCallable)
		static void ReceiveOnPawnPossessed(class APawn* PossessedPawn) {};
	UFUNCTION(BlueprintCallable)
		static void ReceiveOnObjectiveSettingsChange(bool toogleNarrator) {};
	UFUNCTION(BlueprintCallable)
		static void ReceiveOnEnchantmentTriggered(EEnchantmentTypeID TypeID) {};
	UFUNCTION(BlueprintCallable)
		static void ReceiveOnArmorPropertyTriggered(EArmorPropertyID TypeID) {};
	UFUNCTION(BlueprintCallable)
		static void OnStopForceFeedbackEvent(const FName& EventName) {};
	//UFUNCTION(BlueprintCallable)
	//	static void OnSecondaryHighlightTargetChanged(TArray<class AMobCharacter*> Targets, class AMobCharacter* closest) {};
	UFUNCTION(BlueprintCallable)
		static void OnRootPlayerGamepadReleased() {};
	UFUNCTION(BlueprintCallable)
		static void OnRootPlayerGamepadPressed() {};
	UFUNCTION(BlueprintCallable)
		static void OnRootPlayer(bool Pressed) {};
	UFUNCTION(BlueprintCallable)
		static void OnRangedTargetingModeToggle(bool Pressed, bool Gamepad) {};
	UFUNCTION(BlueprintCallable)
		static void OnRangedTargetingModeReleased() {};
	UFUNCTION(BlueprintCallable)
		static void OnRangedTargetingModePressed() {};
	UFUNCTION(BlueprintCallable)
		static void OnRangedAttackButtonGamepadReleased() {};
	UFUNCTION(BlueprintCallable)
		static void OnRangedAttackButtonGamepadPressed() {};
	UFUNCTION(BlueprintCallable)
		static void OnRangedAttackButton(bool Pressed) {};
	UFUNCTION(BlueprintCallable)
		static void OnRangeAttackAxisSecondary(float Value) {};
	UFUNCTION(BlueprintCallable)
		static void OnRangeAttackAxisPrimary(float Value) {};
	UFUNCTION(BlueprintCallable)
		static void OnPreSeamlessTravel() {};
	UFUNCTION(BlueprintCallable)
		static void OnPostSeamlessTravel() {};
	UFUNCTION(BlueprintCallable)
		static void OnPlayForceFeedbackEvent(const FName& EventName, bool Looping) {};
	UFUNCTION(BlueprintCallable)
		static void OnPlayerRespawned() {};
	UFUNCTION(BlueprintCallable)
		static void OnPlayerDeath() {};
	UFUNCTION(BlueprintCallable)
		static void OnMoveButton(bool Pressed) {};
	UFUNCTION(BlueprintCallable)
		static void OnMeleeAttackButtonReleased() {};
	UFUNCTION(BlueprintCallable)
		static void OnMeleeAttackButtonPressed() {};
	UFUNCTION(BlueprintCallable)
		static void OnMeleeAttackButton(bool Pressed, bool Gamepad) {};
	UFUNCTION(BlueprintCallable)
		static void OnLocationClicked(const struct FVector& Location) {};
	UFUNCTION(BlueprintCallable)
		static void OnHotbarItemUsed() {};
	UFUNCTION(BlueprintCallable)
		static void OnHighlightTargetChanged(class AActor* NewTarget, class AActor* oldTarget) {};
	UFUNCTION(BlueprintCallable)
		static void OnFirePerformanceAnalytics() {};
	UFUNCTION(BlueprintCallable)
		static void OnDodgeForwardButton(bool Pressed) {};
	UFUNCTION(BlueprintCallable)
		static void OnDodgeButton(bool Pressed) {};
	UFUNCTION(BlueprintCallable)
		static void OnDebugState() {};
	UFUNCTION(BlueprintCallable)
		static void OnDebugPointer(bool Pressed) {};
	UFUNCTION(BlueprintCallable)
		static void OnCancelTeleport(bool forceCancel) {};
	UFUNCTION(BlueprintCallable)
		static void OnAnyPlayerDamaged(float Damage) {};
	UFUNCTION(BlueprintCallable)
		static void OnActorClicked(class AActor* Actor, EClickTargetType Type) {};
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//	static TEnumAsByte<EPathFollowingRequestResult> MoveToLocation(const struct FVector& Dest, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bProjectDestinationToNavigation, bool bCanStrafe, class UClass* FilterClass, bool bAllowPartialPath);
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//static TEnumAsByte<EPathFollowingRequestResult> MoveToActor(class AActor* Goal, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bCanStrafe, class UClass* FilterClass, bool bAllowPartialPath);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsTeleportListOpen() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsTeleporting() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsInputTypeAllowed(EPlayerInputType InputType, bool Gamepad) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool IsInputCapturedByUI() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool IsInputCapturedByTeleport() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool IsInitialSetupDone() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool IsChatWheelVisible() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool InitialBlueprintSetupComplete() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool HasValidLocalPlayer() { return true; };
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//static class UWalletComponent* GetWalletComponent() { return NULL; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static TArray<class APlayerCharacter*> GetTeleportDependents() { return TArray<class APlayerCharacter*>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static TArray<class APlayerCharacter*> GetTeleportCandidates() { return TArray<class APlayerCharacter*>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int GetPlayerId() { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FString GetPlayerDisplayName() { return FString(); };
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//	static class UPathFollowingComponent* GetPathFollowingComponent() { return NULL; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int GetLocalPlayerIndex() { return 0; };
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//	static class UItemStashComponent* GetItemStashComponent() { return NULL; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetIsMoving() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static class APlayerCharacter* GetControlledPlayerCharacter() { return NULL; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FVector GetAudioListenerLocation() { return FVector(); };
	UFUNCTION(BlueprintCallable)
		static void DodgeInDirection(const FVector& Direction) {};
	//UFUNCTION(BlueprintCallable)
	//	static void ClientDropItems(const FItemDropSource& dropSource, const struct FNetworkedItemDropData& DropData, bool replicateItems, bool elongatedDrops, float dropDelay, float dropDelayCountSpeedUpFactor, EItemRarityChanceCategory rarityChanceCategory) {};
	//UFUNCTION(BlueprintCallable)
	//	static bool ClickyClicked(class UInteractableComponent* clicky) {};
	UFUNCTION(BlueprintCallable)
		static void CenterMouseCursor() {};
	UFUNCTION(BlueprintCallable)
		static void CancelCurrentInputActions() {};
	UFUNCTION(BlueprintCallable)
		static void AdjustCameraFovBasedOnCharacterSpeed() {};
};


// Class Dungeons.PlayerCharacter
// 0x04B0 (0x0EC0 - 0x0A10)
UCLASS(BlueprintType)
class APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()
public:
	struct FScriptMulticastDelegate                    OnPlayerAliveStateChanged;                                // 0x0A10(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	unsigned char                                      UnknownData00[0x18];                                      // 0x0A20(0x0UPlayerExperienceComponent018) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              RollSpeed;                                                // 0x0A38(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              RollZ;                                                    // 0x0A3C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              DodgeCooldownShared;                                      // 0x0A40(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0A44(0x0004) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnPlayerDodgeRollingChanged;                              // 0x0A48(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnPlayerDodgeRollingCooldownChanged;                      // 0x0A58(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnPlayerMultiDodgeChanged;                                // 0x0A68(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnPlayerLoadedInLevel;                                    // 0x0A78(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnPlayerWillRespawn;                                      // 0x0A88(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	unsigned char                                      UnknownData02[0x48];                                      // 0x0A98(0x0048) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnPlayerEnterFreezingWater;                               // 0x0AE0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	unsigned char                                      UnknownData03[0x60];                                      // 0x0AF0(0x0060) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnMissionUnlocked;                                        // 0x0B50(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnMerchantUnlocked;                                       // 0x0B60(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnPlayerGameplayEffectUiAdded;                            // 0x0B70(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnPlayerGameplayEffectUiRemoved;                          // 0x0B80(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnPlayerGameplayEffectUiStackCountChanged;                // 0x0B90(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	unsigned char                                      UnknownData04[0x18];                                      // 0x0BA0(0x0018) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              mPostPopRadius;                                           // 0x0BB8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              mPopCombatCooldown;                                       // 0x0BBC(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              fullTextDisplayTime;                                      // 0x0BC0(0x0004) (ZeroConstructor, IsPlainOldData)
	//TODO look into uint16_t
	uint16_t                                           TNTKillCount;                                             // 0x0BC4(0x0002) (Net, ZeroConstructor, Transient, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EItemRarityChanceCategory)
	EItemRarityChanceCategory                          LastOpenedChestRarity;                                    // 0x0BC6(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData05[0x1];                                       // 0x0BC7(0x0001) MISSED OFFSET
	uint16_t                                           IceWandKillCount;                                         // 0x0BC8(0x0002) (Net, ZeroConstructor, Transient, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               OcelotArmourTracking;                                     // 0x0BCA(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               IceWeaponTracking;                                        // 0x0BCB(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               EmeraldArmourTracking;                                    // 0x0BCC(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData06[0x1];                                       // 0x0BCD(0x0001) MISSED OFFSET
	uint16_t                                           SpinBladeHitCount;                                        // 0x0BCE(0x0002) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData07[0x10];                                      // 0x0BD0(0x0010) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AActor* ElytraLandMarker;                                         // 0x0BE0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TMap<EMaterialTypeEnum, class USoundCue*>          FootstepSoundMap;                                         // 0x0BE8(0x0050) (Edit, BlueprintVisible, ZeroConstructor)
	class USoundCue* LastStepSound;                                            // 0x0C38(0x0008) (ZeroConstructor, IsPlainOldData)
	TMap<EMaterialTypeEnum, class UParticleSystem*>    FootstepParticleMap;                                      // 0x0C40(0x0050) (Edit, BlueprintVisible, ZeroConstructor)
	struct FScriptMulticastDelegate                    OnIsOwnedByHostChanged;                                   // 0x0C90(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UEquipmentComponent* EquipmentComponent;                                       // 0x0CA0(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, Transient, EditConst, InstancedReference, IsPlainOldData)
	class UEquipmentDisplayComponent* EquipmentDisplayComponent;                                // 0x0CA8(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, Transient, EditConst, InstancedReference, IsPlainOldData)
	class UWalletComponent* WalletComponent;                                          // 0x0CB0(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, Transient, EditConst, InstancedReference, IsPlainOldData)
	class UPlayerAvatarComponent* PlayerAvatarComponent;                                    // 0x0CB8(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, Transient, EditConst, InstancedReference, IsPlainOldData)
	class USoulComponent* SoulComponent;                                            // 0x0CC0(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, Transient, EditConst, InstancedReference, IsPlainOldData)
	class UPlayerExperienceComponent* PlayerExperienceComponent;                                // 0x0CC8(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, Transient, EditConst, InstancedReference, IsPlainOldData)
	class UMapPinComponent* MapPinComponent;                                          // 0x0CD0(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, Transient, EditConst, InstancedReference, IsPlainOldData)
	class UTeleportComponent* TeleportComponent;                                        // 0x0CD8(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, Transient, EditConst, InstancedReference, IsPlainOldData)
	class UReviveComponent* ReviveComponent;                                          // 0x0CE0(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, Transient, EditConst, InstancedReference, IsPlainOldData)
	class USoundCue* XPPickupSound;                                            // 0x0CE8(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UAudioComponent* XPPickupAudioComponent;                                   // 0x0CF0(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UItemStashComponent* ItemStashComponent;                                       // 0x0CF8(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, EditConst, InstancedReference, IsPlainOldData)
	class UPickupItemComponent* PickupItemComponent;                                      // 0x0D00(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, EditConst, InstancedReference, IsPlainOldData)
	class UKillTrackerComponent* KillTrackerComponent;                                     // 0x0D08(0x0008) (Edit, ExportObject, ZeroConstructor, DisableEditOnInstance, EditConst, InstancedReference, IsPlainOldData)
	class UMissionProgressComponent* MissionProgressComponent;                                 // 0x0D10(0x0008) (Edit, ExportObject, ZeroConstructor, DisableEditOnInstance, EditConst, InstancedReference, IsPlainOldData)
	class UCharacterSerializeComponent* CharacterLazySaveComponent;                               // 0x0D18(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UCosmeticsComponent* CosmeticsComponent;                                       // 0x0D20(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UCosmeticsDisplayComponent* CosmeticsDisplayComponent;                                // 0x0D28(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UDamageNumberBatchingComponent* DamageNumberBatchingComponent;                            // 0x0D30(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStatTrackerComponent* StatTrackerComponent;                                     // 0x0D38(0x0008) (Edit, ExportObject, ZeroConstructor, DisableEditOnInstance, EditConst, InstancedReference, IsPlainOldData)
	class UClass* DefaultAnimationsInstance;                                // 0x0D40(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage* StunnedMontage;                                           // 0x0D48(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class ULovikaSpringArmComponent* CameraSpringArm;                                          // 0x0D50(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	class ULovikaSpringArmComponent* LMPCameraSpringArm;                                       // 0x0D58(0x0008) (BlueprintVisible, ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	struct FScriptMulticastDelegate                    OnPlayerHealthChanged;                                    // 0x0D60(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnPlayerNumberChanged;                                    // 0x0D70(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnPlayerStateChanged;                                     // 0x0D80(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnAttackVariantAnimationsAssigned;                        // 0x0D90(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              AudioListenerTweenAlpha;                                  // 0x0DA0(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      IsViewTarget : 1;                                         // 0x0DA4(0x0001) (BlueprintVisible)
	unsigned char                                      UnknownData08[0xB];                                       // 0x0DA5(0x000B) MISSED OFFSET
	class UAudioComponent* mPlayerDeathSoundComponent;                               // 0x0DB0(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UAudioComponent* mPlayeDownSoundComponent;                                 // 0x0DB8(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UCameraComponent* mDetachedCameraReference;                                 // 0x0DC0(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USceneComponent* mCameraParentComponent;                                   // 0x0DC8(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData09[0x20];                                      // 0x0DD0(0x0020) MISSED OFFSET
	class UInteractableComponent* InteractableComponent;                                    // 0x0DF0(0x0008) (Edit, ExportObject, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData10[0x4C];                                      // 0x0DF8(0x004C) MISSED OFFSET
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EAPlayerCharacterInternal_ELoadedType)
	EAPlayerCharacterInternal_ELoadedType              mLoadedType;                                              // 0x0E44(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData11[0x3];                                       // 0x0DF8(0x0003) FIX WRONG TYPE SIZE OF PREVIOUS PROPERTY
	unsigned char                                      UnknownData12[0x78];                                      // 0x0E48(0x0078) MISSED OFFSET

	UFUNCTION(BlueprintCallable)
		static void TeleportToFriend(class APlayerCharacter* Player) {};
	UFUNCTION(BlueprintCallable)
		static float TeleportPlayerToActor(class APlayerState* targetPlayerState) { return 0; };
	UFUNCTION(BlueprintCallable)
		static void SetReadyToPlayInternal() {};
	UFUNCTION(BlueprintCallable)
		static void SetReadyToPlay() {};
	UFUNCTION(BlueprintCallable)
		static void SetIsInInventory(bool inInventory) {};
	UFUNCTION(BlueprintCallable)
		static void ServerlaunchPlayer(const struct FVector& Velocity) {};
	UFUNCTION(BlueprintCallable)
		static void SalvagePendingRewardItem() {};
	UFUNCTION(BlueprintCallable)
		static void RestartAtCheckpoint() {};
	UFUNCTION(BlueprintCallable)
		static void RespawnPlayerMulticast() {};
	UFUNCTION(BlueprintCallable)
		static bool PopToPlayer(const struct FVector& playerPosition, float popRadiusAngle) { return true; };
	UFUNCTION(BlueprintCallable)
		static void OnRep_TNTKillCount() {};
	UFUNCTION(BlueprintCallable)
		static void OnRep_SpinBladeHitCount() {};
	UFUNCTION(BlueprintCallable)
		static void OnRep_OpenedChestRarity() {};
	UFUNCTION(BlueprintCallable)
		static void OnRep_OcelotArmourTracking() {};
	UFUNCTION(BlueprintCallable)
		static void OnRep_LoadedType() {};
	UFUNCTION(BlueprintCallable)
		static void OnRep_IceWeaponTracking() {};
	UFUNCTION(BlueprintCallable)
		static void OnRep_IceWandKillCount() {};
	UFUNCTION(BlueprintCallable)
		static void OnRep_EmeraldArmourTracking() {};
	UFUNCTION(BlueprintCallable)
		static void OnPlayerTeleported() {};
	UFUNCTION(BlueprintCallable)
		static void OnPlayerNumberUpdated() {};
	UFUNCTION(BlueprintCallable)
		static void OnPlayerAction(class ABasePlayerController* PlayerController) {};
	UFUNCTION(BlueprintCallable)
		static void OnOtherPlayerLeft() {};
	UFUNCTION(BlueprintCallable)
		static void OnOtherPlayerJoined() {};
	UFUNCTION(BlueprintCallable)
		static void OnLocalPlayerTeleported() {};
	UFUNCTION(BlueprintCallable)
		static void OnLlamaOffering() {};
	UFUNCTION(BlueprintCallable)
		static void OnFootstep() {};
	UFUNCTION(BlueprintCallable)
		static void OnCharacterDown() {};
	UFUNCTION(BlueprintCallable)
		static void OnCapsuleEndOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex) {};
	UFUNCTION(BlueprintCallable)
		static void OnCapsuleBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult) {};
	UFUNCTION(BlueprintCallable)
		static bool LaunchCharacterToPos(const struct FVector& Destination, float launchSpeed, bool traceFullPath) { return true; };
	UFUNCTION(BlueprintCallable)
		static void IsOwnedByHostChanged() {};
	UFUNCTION(BlueprintCallable,BlueprintPure)
		static bool IsOwnedByHost() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsOnGround() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsLoadedInLevel() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsIcyBreath() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsDodgeRolling() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsDodgeOnCooldown() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsAllowedToPerformAction() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool InWorldAndAlive() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool HasPendingRewardItem() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool HasDodgesLeft() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool HasBeenInCombat() { return true; };
	UFUNCTION(BlueprintCallable)
		static void HandleInteraction(class ACharacter* interactor) {};
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static ETeleportState GetTeleportState() { return (ETeleportState)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<class APlayerCharacter*> GetTeleportDependents() { return TArray<class APlayerCharacter*>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<class APlayerCharacter*> GetTeleportCandidates() { return TArray<class APlayerCharacter*>(); };
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//	static class UStatTrackerComponent* GetStatTracker() { return NULL; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int GetPlayerNumber() { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static struct FColor GetPlayerColor() { return FColor(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static struct FAvatarData GetPlayerAvatarData() { return FAvatarData(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static struct FInventoryItemData GetPendingRewardItem() { return FInventoryItemData(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetLocalPlayerDisplayText() { return FText(); };
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//	static class UItemSlot* GetItemSlotOfType(ESlotType Type, int Index) { return NULL; };
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//	static class UEffectBasedCooldownProvider* GetDodgeCooldownProvider() { return NULL; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static float GetDodgeCooldownFraction() { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int GetCharacterLevel() { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EAliveState GetAliveState() { return (EAliveState)0; };
	UFUNCTION(BlueprintCallable)
		static void ClientUnlockMerchant(class UClass* MerchantDef) {};
	UFUNCTION(BlueprintCallable)
		static void ClientUnlockBonusMission(ELevelNames Level) {};
	UFUNCTION(BlueprintCallable)
		static void Client_OnLlamaOffering() {};
	UFUNCTION(BlueprintCallable)
		static void ClaimPendingRewardItem() {};
	UFUNCTION(BlueprintCallable,BlueprintPure)
		static bool CanPop() { return true; };
	UFUNCTION(BlueprintCallable,BlueprintPure)
		static bool CanDodge() { return true; };
	UFUNCTION(BlueprintCallable)
		static void ApplyMaterialToMesh(class UMaterialInstance* Material) {};
	//UFUNCTION(BlueprintCallable)
	//	static void ActivateSupplies(class URefreshSuppliesComponent* Component) {};
};


// ==================================================================================================================================================================
// ==================================================================================================================================================================
// |||                                                                 MERCHANT CLASSES                                                                           |||
// ==================================================================================================================================================================
// ==================================================================================================================================================================

// Class Dungeons.MerchantSubobjectBase
// 0x0008 (0x0030 - 0x0028)
UCLASS()
class UMerchantSubobjectBase : public UObject
{
	GENERATED_BODY()
public:
	class AMerchantBase* mMerchant;                                                // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
};

// Class Dungeons.MerchantQuestBase
// 0x0000 (0x0030 - 0x0030)
UCLASS(BlueprintType)
class UMerchantQuestBase : public UMerchantSubobjectBase
{
	GENERATED_BODY()
		UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsCompleted() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetProgressText() { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static float GetProgressFraction() { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetExplainerText() { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetCountText() { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int GetCompletedCount() { return 1; };
};

// Class Dungeons.MerchantSlotBase
// 0x0030 (0x0060 - 0x0030)
UCLASS(BlueprintType)
class UMerchantSlotBase : public UMerchantSubobjectBase
{
	GENERATED_BODY()
public:
	class UMerchantQuestBase* mUnlockQuest;                                             // 0x0030(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x18];                                      // 0x0038(0x0018) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnMerchantSlotChanged;                                    // 0x0050(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsUnlocked() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool HasPrice() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static struct FMerchantDisplayPrice GetPrice() { return FMerchantDisplayPrice(); };
	class UMerchantQuestBase* GetActiveUnlockQuest();
};


// Class Dungeons.MerchantItemSlotBase
// 0x0028 (0x0088 - 0x0060)
UCLASS(BlueprintType)
class UMerchantItemSlotBase : public UMerchantSlotBase
{
	GENERATED_BODY()
public:
	class UInventoryItem* mDisplayItemCache;                                        // 0x0060(0x0008) (ZeroConstructor, IsPlainOldData)
	class UInventoryItem* mDeliveredDisplayItem;                                    // 0x0068(0x0008) (ZeroConstructor, IsPlainOldData)
	class UMerchantItemGeneratorBase* mItemGenerator;                                           // 0x0070(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FScriptMulticastDelegate                    OnMerchantItemSlotChanged;                                // 0x0078(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsReserved() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsItemUnlocked() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsItemReserved() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool HasItem() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static struct FInventoryItemData GetItem() { return FInventoryItemData(); };
	class UInventoryItem* GetDisplayItemCache();
};

// Class Dungeons.MerchantTransactionBase
// 0x0028 (0x0058 - 0x0030)
UCLASS(BlueprintType)
class UMerchantTransactionBase : public UMerchantSubobjectBase
{
	GENERATED_BODY()
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x0030(0x0018) MISSED OFFSET
	FScriptMulticastDelegate                           OnMerchantTransactionChanged;                             // 0x0048(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)

	UFUNCTION(BlueprintCallable)
		static bool TryExecute() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FProblemStatus QueryProblemStatus(bool HasProblem) { return FProblemStatus(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool HasPrice() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EMerchantTransactionStatusReason GetSuccessStatusReason() { return (EMerchantTransactionStatusReason)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EMerchantTransactionStatusReason GetStatusReason() { return (EMerchantTransactionStatusReason)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<FItemBulletPoint> GetStatusBulletPoints() { return TArray<FItemBulletPoint>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FMerchantDisplayPrice GetPrice() { return FMerchantDisplayPrice(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool CanSelectAllRequiredSelections() { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool CanExecute() { return true; };
};

// Class Dungeons.MerchantBase
// 0x0310 (0x0640 - 0x0330)
UCLASS(BlueprintType)
class AMerchantBase : public AInfo
{
	GENERATED_BODY()
public:
	unsigned char                                      UnknownData00[0xC8];                                      // 0x0330(0x00C8) MISSED OFFSET
	TArray<class UMerchantSubobjectBase*>              mSubObjects;                                              // 0x03F8(0x0010) (ZeroConstructor, Transient)
	TArray<class UMerchantSlotBase*>                   slots;                                                    // 0x0408(0x0010) (ZeroConstructor, Transient)
	TMap<class UClass*, class UMerchantTransactionBase*> transactions;                                             // 0x0418(0x0050) (ZeroConstructor, Transient)
	TMap<class UClass*, class UMerchantSelectionBase*> selections;                                               // 0x0468(0x0050) (ZeroConstructor, Transient)
	class USelectionChain* mSelectionFocus;                                          // 0x04B8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x50];                                      // 0x04C0(0x0050) UNKNOWN PROPERTY: SetProperty Dungeons.MerchantBase.mTransactionClasses
	unsigned char                                      UnknownData02[0x50];                                      // 0x0510(0x0050) UNKNOWN PROPERTY: SetProperty Dungeons.MerchantBase.mSelectionClasses
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                              mDisplayDescription;                                      // 0x0560(0x0018) (Transient)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemBulletPoint>                           mDisplayBulletPoints;                                     // 0x0578(0x0010) (ZeroConstructor, Transient)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                              mLockedSlotsHint;                                         // 0x0588(0x0018) (Transient)
	class UMerchantQuestBase* mRestockQuest;                                            // 0x05A0(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UClass* mPermanentSelectionClass;                                 // 0x05A8(0x0008) (ZeroConstructor, IsPlainOldData)
	class UClass* mAlwaysSelectSelectionClass;                              // 0x05B0(0x0008) (ZeroConstructor, IsPlainOldData)
	class UMerchantPricingComponent* mMerchantPricingComponent;                                // 0x05B8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UMerchantCurrencyComponent* mMerchantCurrencyComponent;                               // 0x05C0(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class APlayerCharacter* mPlayerCharacterOwner;                                    // 0x05C8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData03[0x50];                                      // 0x05D0(0x0050) UNKNOWN PROPERTY: SetProperty Dungeons.MerchantBase.mPermanentTransactionClasses
	unsigned char                                      UnknownData04[0x20];                                      // 0x0620(0x0020) MISSED OFFSET
};


// ==================================================================================================================================================================
// ==================================================================================================================================================================
// |||                                                                      MISSION CLASSES                                                                       |||
// ==================================================================================================================================================================
// ==================================================================================================================================================================


// Class Dungeons.MissionChancesUtil
// 0x0000 (0x0028 - 0x0028)
UCLASS(BlueprintType)
class UMissionChancesUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		UFUNCTION(BlueprintCallable,BlueprintPure)
		static EMobStatus GetMobStatus(const FMissionMobChance& mobChance, class AActor* progressOwner) { return (EMobStatus)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetMobChanceText(const FMissionMobChance& mobChance) { return FText(); };
	class UClass* GetMobChanceIconClass(class UObject* WorldContextObject, const struct FMissionMobChance& mobChance);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetMobChanceDLCText(const FMissionMobChance& mobChance) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<FMissionProbability> GetMissionProbabilities(const FMissionState& MissionState) { return TArray<FMissionProbability>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetMissionChancesTypeText(EMissionChancesType chancesType) { return FText(); };
	TArray<EMissionChancesType> GetMissionChancesTypesFiltered(ELevelNames levelName, TArray<EMissionChancesType> AllowedTypes);
	TArray<EMissionChancesType> GetMissionChancesTypes(ELevelNames levelName);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetMissionChancesText(const FMissionChances& chances) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FMissionChances GetMissionChances(const FMissionState& MissionState, EMissionChancesType chancesType) { return FMissionChances(); };
	TArray<FMissionItemTypeChance> GetMapRewardItemTypeChances(const FMissionDifficulty& MissionDifficulty);
	TArray<FMissionItemTagChance> GetMapRewardItemTagChances(ELevelNames levelName);
	TArray<FMissionItemRarityChance> GetMapRewardItemRarityChances(ELevelNames levelName);
	TArray<FMissionItemTypeChance> GetMapLootItemTypeChances(const FMissionDifficulty& MissionDifficulty);
	TArray<FMissionItemTypeChance> GetMapArtifactItemTypeChances(const FMissionDifficulty& MissionDifficulty);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetCanShowItemType(const FSerializableItemId& ItemId, class AActor* progressOwner) { return true; };
};


// Class Dungeons.MissionDefs
// 0x0000 (0x0028 - 0x0028)
UCLASS(BlueprintType)
class UMissionDefs : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
		UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsTutorial(ELevelNames levelName) { return false; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsTrial(ELevelNames levelName) { return false; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsSecret(ELevelNames levelName) { return false; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsSalvageEnabled(ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsMissionThreatLevelUnlockedByDefault(ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsMissionThreatLevelSelectorHidden(ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsHyperMission(ELevelNames levelName) { return false; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static float GetThreatLevelFraction(EThreatLevel threatLevel) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetSecretUnlockInMissionAsRequirementText(ELevelNames foundInMission) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<ELevelNames> GetRequiredMissions(ELevelNames levelName) { return TArray<ELevelNames>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static int GetRecommendedTotalGearItemPower(const FMissionDifficulty& MissionDifficulty) { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static ELevelVariationType GetMissionVariationType(ELevelNames levelName) { return (ELevelVariationType)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EMissionTheme GetMissionUITheme(ELevelNames levelName) { return (EMissionTheme)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetMissionTrialText(ELevelNames mission) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetMissionRequiresStartConfirmation(ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool GetMissionRequiresOfferings(ELevelNames levelName) { return true; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetMissionLockedText(ELevelNames mission) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetMissionLockedDescription(ELevelNames mission) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static class UTexture2D* GetMissionLoadingScreenTexture(ELevelNames levelName) { return NULL; };
	UFUNCTION(BlueprintCallable)
		static void GetMissionLoadingScreenSoftTexture(ELevelNames levelName) {};
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EExtraChallenge GetMissionExtraChallenge(ELevelNames levelName) { return (EExtraChallenge)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetMissionDisplayStoryTitle(ELevelNames levelName) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetMissionDisplayStoryContents(ELevelNames levelName) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetMissionDisplayName(ELevelNames levelName) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetMissionConfirmStartWarning(ELevelNames levelName) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetMissionConfirmStartTitle(ELevelNames levelName) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetMissionAsRequirementToolTipText(ELevelNames LevelNameRequired) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FText GetMissionAsRequirementText(ELevelNames requirement) { return FText(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<FThreatDescription> GetMapThreatLevelDescriptions(const FMissionDifficulty& MissionDifficulty, class APlayerCharacter* Player, int DisplayGearPower) { return TArray<FThreatDescription>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EThreatLevel GetLastSelectableThreatLevel(ELevelNames levelName, EGameDifficulty difficulty) { return (EThreatLevel)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FDifficultyRecommendation GetGearPowerDifficultyRecommendation(ELevelNames levelName, int DisplayGearPower) { return FDifficultyRecommendation(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static EThreatLevel GetFirstSelectableThreatLevel(ELevelNames levelName, EGameDifficulty difficulty) { return (EThreatLevel)0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static float GetDisplayGearPowerGlobalThreatFraction(int DisplayGearPower) { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static float GetDifficultyThreatGlobalThreatFraction(EGameDifficulty difficulty, EThreatLevel threatLevel) { return 0; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<ELevelNames> GetAllNonDisabledMissions() { return TArray<ELevelNames>(); };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<FAffectorInfo> GetAffectorInfo(ELevelNames mission) { return TArray<FAffectorInfo>(); };
};


// Class Dungeons.MissionDifficultyUtil
// 0x0000 (0x0028 - 0x0028)
UCLASS(BlueprintType)
class UMissionDifficultyUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		bool IsMissionDifficultyValid(const FMissionDifficulty& MissionDifficulty);
};


// Class Dungeons.MissionInterestUtil
// 0x0000 (0x0028 - 0x0028)
UCLASS(BlueprintType)
class UMissionInterestUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		FText GetMissionInterestText(EMissionInterest interestType, int Count);
	bool GetMissionInterestIsNew(EMissionInterest interestType);
	FText GetMissionInterestCarouselText(const FMissionInterestCarousel& interestCarousel);
};


// Class Dungeons.MissionLootCameraActor
// 0x0000 (0x0890 - 0x0890)
UCLASS(BlueprintType)
class AMissionLootCameraActor : public ACameraActor
{
	GENERATED_BODY()
};


// Class Dungeons.MissionOfferingsTransactionBase
// 0x0008 (0x0060 - 0x0058)
UCLASS(BlueprintType)
class UMissionOfferingsTransactionBase : public UMerchantTransactionBase
{
	GENERATED_BODY()
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0058(0x0008) MISSED OFFSET

	FMissionOfferings GetMissionOfferings();
	ELevelNames GetMission();
	bool GetIsItemBeingOffered(class UInventoryItem* Item);
};


// Class Dungeons.MissionOfferingsUtil
// 0x0000 (0x0028 - 0x0028)
UCLASS(BlueprintType)
class UMissionOfferingsUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		bool NotEqual_MissionOfferings(const FMissionOfferings& A, const FMissionOfferings& B);
	TMap<EItemArchetype, int> GetOfferingsArchetypeCounts(const FMissionOfferings& offerings);
	bool EqualEqual_MissionOfferings(const FMissionOfferings& A, const FMissionOfferings& B);
};


// Class Dungeons.MissionPresentationHandler
// 0x0070 (0x0168 - 0x00F8)
UCLASS(BlueprintType)
class UMissionPresentationHandler : public UActorComponent
{
	GENERATED_BODY()
public:
	struct FScriptMulticastDelegate                    OnTriggerIntroMusic;                                      // 0x00F8(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTriggerOutroMusic;                                      // 0x0108(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnObjectiveMusicStart;                                    // 0x0118(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FMissionPresentation                        mPresentationData;                                        // 0x0128(0x0020) (BlueprintVisible, BlueprintReadOnly, Net)
	struct FBox                                        mMissionBoundingBox;                                      // 0x0148(0x001C) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0164(0x0004) MISSED OFFSET

	void OnRep_SetMissionBoundingBox();
	void OnRep_PresentationData();
	void EndCurrentObjective();
};


// Class Dungeons.MissionQuery
// 0x0000 (0x0028 - 0x0028)
UCLASS(BlueprintType)
class UMissionQuery : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		void GetPropNamesForTile(class UObject* WorldContextObject, const FString& TileName, TArray<FString>* PropNames);
	ELevelNames GetLevelName(class UObject* WorldContextObject);
};


// Class Dungeons.MissionRequestUtil
// 0x0000 (0x0028 - 0x0028)
UCLASS(BlueprintType)
class UMissionRequestUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		FMissionState GetMissionState(const FMissionRequest& Request);
	EMissionEditor GetMissionRequestDesiredEditor(const FMissionRequest& State);
	FMissionRequest CreateMissionRequest(class APlayerCharacter* Player, EMissionRequestType requestType, const FMissionSelection& Selection, int Seed, const FMissionOfferings& offerings);
};


// Class Dungeons.MissionSelectorComponent
// 0x0040 (0x0138 - 0x00F8)
UCLASS(BlueprintType)
class UMissionSelectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	struct FScriptMulticastDelegate                    OnLevelRequested;                                         // 0x00F8(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnLevelRequestFinished;                                   // 0x0108(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnLevelStarting;                                          // 0x0118(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class ALobbyActor* mLobbyActor;                                              // 0x0128(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0130(0x0008) MISSED OFFSET

	bool TryStartMissionSelection(class APlayerCharacter* RequestingPlayer, const FMissionSelection& MissionSelection);
	bool TryContinueMission(class APlayerCharacter* RequestingPlayer, ELevelNames levelName);
	void TravelToMission();
	void ServerRequestLevel(class APlayerCharacter* requesterPlayer, const FMissionRequest& MissionRequest);
	void ServerReject();
	void ServerAccept();
	void HandleLogout();
	void ClientRequestFinished();
	void ClientLevelStarting(const FLevelSettings& LevelSettings);
	void ClientLevelRequested(const FLevelRequest& Request);
};


// Class Dungeons.MissionStateUtil
// 0x0000 (0x0028 - 0x0028)
UCLASS(BlueprintType)
class UMissionStateUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		int GetTotalDisplayItemPower(const FMissionState& MissionState);
	EThreatLevel getThreatLevel(const FMissionState& MissionState);
	FMissionDifficulty getMissionDifficulty(const FMissionState& MissionState);
	ELevelNames GetLevelName(const FMissionState& MissionState);
	FEndlessStruggle getEndlessStruggle(const FMissionState& MissionState);
	EGameDifficulty getDifficulty(const FMissionState& MissionState);
	TArray<FItemBulletPoint> GetBulletPoints(const FMissionState& MissionState);
};


// Class Dungeons.MissionThemeDefs
// 0x0000 (0x0028 - 0x0028)
UCLASS(BlueprintType)
class UMissionThemeDefs : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		void unloadThemeTextures(class UObject* WorldContextObject, EMissionTheme Theme);
	void preloadThemeTextures(class UObject* WorldContextObject, EMissionTheme Theme);
	FName getRowName(EMissionTheme Theme);
	FText getLockedDisplayText(EMissionTheme Theme);
	FText getLockedDescriptionText(EMissionTheme Theme);
	FText GetDisplayText(EMissionTheme Theme);
};


// Class Dungeons.MissionThemeLibrary
// 0x0058 (0x0080 - 0x0028)
UCLASS(BlueprintType)
class UMissionThemeLibrary : public UObject
{
	GENERATED_BODY()
public:
	class UDataTable* mThemeDataTable;                                          // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	TMap<EMissionTheme, class UTextureCache*>          mTextureCaches;                                           // 0x0030(0x0050) (ZeroConstructor)
};
