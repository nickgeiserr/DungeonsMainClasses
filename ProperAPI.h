// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/ActorComponent.h"
#include "Internationalization/Text.h"
#include "Engine/Texture2D.h"
#include "ProperAPI.generated.h"

UENUM()
enum EPlatformType
{
    EPlatformType__E_PLATFORM_XBONE = 0,
    EPlatformType__E_PLATFORM_PC = 1,
    EPlatformType__E_PLATFORM_PS4 = 2,
    EPlatformType__E_PLATFORM_SWITCH = 3,
    EPlatformType__E_PLATFORM_MAC = 4,
    EPlatformType__E_PLATFORM_IOS = 5,
    EPlatformType__E_PLATFORM_ANDROID = 6,
    EPlatformType__E_PLATFORM_LINUX = 7,
    EPlatformType__E_PLATFORM_MAX = 8
};

UENUM()
enum ESubPlatformType
{
    ESubPlatformType__E_SUBPLATFORM_BASE = 0,
    ESubPlatformType__E_SUBPLATFORM_XBONE_S = 1,
    ESubPlatformType__E_SUBPLATFORM_XBONE_X = 2,
    ESubPlatformType__E_SUBPLATFORM_XBONE_LOCKHART = 3,
    ESubPlatformType__E_SUBPLATFORM_XBONE_SERIES_X = 4,
    ESubPlatformType__E_SUBPLATFORM_PS4_PRO = 5,
    ESubPlatformType__E_SUBPLATFORM_PS5 = 6,
    ESubPlatformType__E_SUBPLATFORM_MAX = 7
};

UENUM()
enum EConfigurationType
{
    EConfigurationType__E_CONFIG_DEBUG = 0,
    EConfigurationType__E_CONFIG_DEVELOPMENT = 1,
    EConfigurationType__E_CONFIG_TEST = 2,
    EConfigurationType__E_CONFIG_SHIPPING = 3,
    EConfigurationType__E_CONFIG_MAX = 4
};

UENUM()
enum class EEnchantmentTypeID : uint8
{
    EEnchantmentTypeID__Unset = 0,
    EEnchantmentTypeID__Sharpness = 1,
    EEnchantmentTypeID__Knockback = 2,
    EEnchantmentTypeID__Looting = 3,
    EEnchantmentTypeID__Prospector = 4,
    EEnchantmentTypeID__FireAspect = 5,
    EEnchantmentTypeID__Rampaging = 6,
    EEnchantmentTypeID__Exploding = 7,
    EEnchantmentTypeID__CriticalHit = 8,
    EEnchantmentTypeID__Freezing = 9,
    EEnchantmentTypeID__PoisonedMelee = 10,
    EEnchantmentTypeID__JunglePoisonMelee = 11,
    EEnchantmentTypeID__Leeching = 12,
    EEnchantmentTypeID__Aiding = 13,
    EEnchantmentTypeID__GravityMelee = 14,
    EEnchantmentTypeID__EnigmaResonatorMelee = 15,
    EEnchantmentTypeID__AnimaConduitMelee = 16,
    EEnchantmentTypeID__Stunning = 17,
    EEnchantmentTypeID__CaveSpiderPoisonEnchantment = 18,
    EEnchantmentTypeID__Swirling = 19,
    EEnchantmentTypeID__Smiting = 20,
    EEnchantmentTypeID__Committed = 21,
    EEnchantmentTypeID__SoulSiphon = 22,
    EEnchantmentTypeID__RadianceMelee = 23,
    EEnchantmentTypeID__Chains = 24,
    EEnchantmentTypeID__Thundering = 25,
    EEnchantmentTypeID__Echo = 26,
    EEnchantmentTypeID__Shockwave = 27,
    EEnchantmentTypeID__Weakening = 28,
    EEnchantmentTypeID__BusyBee = 29,
    EEnchantmentTypeID__DynamoMelee = 30,
    EEnchantmentTypeID__BaneOfIllagers = 31,
    EEnchantmentTypeID__Rushdown = 32,
    EEnchantmentTypeID__TempoTheft = 33,
    EEnchantmentTypeID__AlacrityAdjustment = 34,
    EEnchantmentTypeID__BowsBoon = 35,
    EEnchantmentTypeID__Ricochet = 36,
    EEnchantmentTypeID__Power = 37,
    EEnchantmentTypeID__Punch = 38,
    EEnchantmentTypeID__Infinity = 39,
    EEnchantmentTypeID__MultiShot = 40,
    EEnchantmentTypeID__Piercing = 41,
    EEnchantmentTypeID__ChainReaction = 42,
    EEnchantmentTypeID__Gravity = 43,
    EEnchantmentTypeID__HuntingBowEnchantment = 44,
    EEnchantmentTypeID__EnigmaResonatorRanged = 45,
    EEnchantmentTypeID__AnimaConduitRanged = 46,
    EEnchantmentTypeID__PoisonedRanged = 47,
    EEnchantmentTypeID__JunglePoisonRanged = 48,
    EEnchantmentTypeID__FreezingRanged = 49,
    EEnchantmentTypeID__RapidFire = 50,
    EEnchantmentTypeID__Supercharge = 51,
    EEnchantmentTypeID__BonusShot = 52,
    EEnchantmentTypeID__Unchanting = 53,
    EEnchantmentTypeID__FuseShot = 54,
    EEnchantmentTypeID__RadianceRanged = 55,
    EEnchantmentTypeID__Accelerating = 56,
    EEnchantmentTypeID__Growing = 57,
    EEnchantmentTypeID__WildRage = 58,
    EEnchantmentTypeID__SlowBowEnchantment = 59,
    EEnchantmentTypeID__DynamoRanged = 60,
    EEnchantmentTypeID__BurstBowstring = 61,
    EEnchantmentTypeID__WindBowEnchantment = 62,
    EEnchantmentTypeID__FreezingAoe = 63,
    EEnchantmentTypeID__Protection = 64,
    EEnchantmentTypeID__Celerity = 65,
    EEnchantmentTypeID__FinalShout = 66,
    EEnchantmentTypeID__Deflecting = 67,
    EEnchantmentTypeID__Regeneration = 68,
    EEnchantmentTypeID__Thorns = 69,
    EEnchantmentTypeID__Altruistic = 70,
    EEnchantmentTypeID__Shielding = 71,
    EEnchantmentTypeID__Barrier = 72,
    EEnchantmentTypeID__HuntingBowTaggedEnchantment = 73,
    EEnchantmentTypeID__Recycler = 74,
    EEnchantmentTypeID__Chilling = 75,
    EEnchantmentTypeID__Cowardice = 76,
    EEnchantmentTypeID__Electrified = 77,
    EEnchantmentTypeID__Burning = 78,
    EEnchantmentTypeID__Snowing = 79,
    EEnchantmentTypeID__GravityPulse = 80,
    EEnchantmentTypeID__FireTrail = 81,
    EEnchantmentTypeID__Frenzied = 82,
    EEnchantmentTypeID__Swiftfooted = 83,
    EEnchantmentTypeID__SpiritSpeed = 84,
    EEnchantmentTypeID__PotionFortification = 85,
    EEnchantmentTypeID__FoodReserves = 86,
    EEnchantmentTypeID__SurpriseGift = 87,
    EEnchantmentTypeID__DoubleDamage = 88,
    EEnchantmentTypeID__FastAttack = 89,
    EEnchantmentTypeID__Quick = 90,
    EEnchantmentTypeID__HealthSynergy = 91,
    EEnchantmentTypeID__SpeedSynergy = 92,
    EEnchantmentTypeID__Explorer = 93,
    EEnchantmentTypeID__VesselTrail = 94,
    EEnchantmentTypeID__SlowResistance = 95,
    EEnchantmentTypeID__SlowImmunity = 96,
    EEnchantmentTypeID__TumbleBee = 97,
    EEnchantmentTypeID__BagOfSouls = 98,
    EEnchantmentTypeID__Acrobat = 99,
    EEnchantmentTypeID__PushVolumeImmunity = 100,
    EEnchantmentTypeID__WindResistance = 101,
    EEnchantmentTypeID__WindImmunity = 102,
    EEnchantmentTypeID__RollCharge = 103,
    EEnchantmentTypeID__MultiDodge = 104,
    EEnchantmentTypeID__EmeraldDivination = 105,
    EEnchantmentTypeID__DeathBarter = 106,
    EEnchantmentTypeID__ResurrectionSurge = 107,
    EEnchantmentTypeID__Huge = 108,
    EEnchantmentTypeID__Invisible = 109,
    EEnchantmentTypeID__Last = 110,
    EEnchantmentTypeID__EEnchantmentTypeID_MAX = 111
};

UENUM()
enum class EEnchantmentCategory : uint8
{
    EEnchantmentCategory__Unset = 0,
    EEnchantmentCategory__Melee = 1,
    EEnchantmentCategory__Ranged = 2,
    EEnchantmentCategory__Aoe = 3,
    EEnchantmentCategory__Armor = 4,
    EEnchantmentCategory__Permanent = 5,
    EEnchantmentCategory__EEnchantmentCategory_MAX = 6
};


UENUM()
enum class EEnchantmentTag : uint8
{
    EEnchantmentTag__Stacking = 0,
    EEnchantmentTag__Multi = 1,
    EEnchantmentTag__SoulUsage = 2,
    EEnchantmentTag__ChargingWeaponsOnly = 3,
    EEnchantmentTag__EEnchantmentTag_MAX = 4
};


UENUM()
enum class EEnchantmentClassification : uint8
{
    EEnchantmentClassification__Unset = 0,
    EEnchantmentClassification__Damage = 1,
    EEnchantmentClassification__Offense = 2,
    EEnchantmentClassification__Defense = 3,
    EEnchantmentClassification__EEnchantmentClassification_MAX = 4
};

UENUM()
enum class EEnchantmentRarity : uint8
{
    EEnchantmentRarity__Common = 0,
    EEnchantmentRarity__Powerful = 1,
    EEnchantmentRarity__EEnchantmentRarity_MAX = 2
};

UENUM()
enum class EBulletIcon : uint8
{
    EBulletIcon__Generic = 0,
    EBulletIcon__ItemPower = 1,
    EBulletIcon__SoulGather = 2,
    EBulletIcon__SoulUse = 3,
    EBulletIcon__Cooldown = 4,
    EBulletIcon__Common = 5,
    EBulletIcon__Rare = 6,
    EBulletIcon__Unique = 7,
    EBulletIcon__SeasonalLimited = 8,
    EBulletIcon__EBulletIcon_MAX = 9
};

UENUM()
enum class EItemTagLevel : uint8
{
    ItemTagLevel__Normal = 0,
    ItemTagLevel__Bright = 1,
    ItemTagLevel__Diamond = 2,
    ItemTagLevel__Last = 3,
    ItemTagLevel__ItemTagLevel_MAX = 4
};


UENUM()
enum class EItemTag : uint8
{
    ItemTag__Unset = 0,
    ItemTag__HealthPotion = 1,
    ItemTag__Arrow = 2,
    ItemTag__BurningArrow = 3,
    ItemTag__FireworksArrow = 4,
    ItemTag__TormentProjectile = 5,
    ItemTag__HeavyHarpoon = 6,
    ItemTag__MeleeWeapon = 7,
    ItemTag__RangedWeapon = 8,
    ItemTag__Armor = 9,
    ItemTag__Currency = 10,
    ItemTag__Item = 11,
    ItemTag__Last = 12,
    ItemTag__ItemTag_MAX = 13
};

USTRUCT()
struct FItemBulletPoint
{
    GENERATED_BODY()
    FText                                              Text;                                                     // 0x0000(0x0018) (BlueprintVisible, BlueprintReadOnly)
    EBulletIcon                                        Icon;                                                     // 0x0018(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
    EItemTag                                           TagIcon;                                                  // 0x0019(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
    bool                                               Upgraded;                                                 // 0x001A(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
    unsigned char                                      UnknownData00[0x5];                                       // 0x001B(0x0005) MISSED OFFSET
};

UCLASS(BlueprintType)
class UGearUtil : public UActorComponent
{
    GENERATED_BODY()
public:
    unsigned char                                      UnknownData00[0x10];                                      // 0x00F8(0x0010) MISSED OFFSET
};

UCLASS(BlueprintType) // Class Dungeons.Enchantment
class UEnchantment : public UGearUtil
{
    GENERATED_BODY()
public:
    unsigned char                                      UnknownData00[0xD0];                                      // 0x0108(0x00D0) MISSED OFFSET
    int                                                Level;                                                    // 0x01D8(0x0004) (Edit, BlueprintVisible, Net, ZeroConstructor, IsPlainOldData)
    EEnchantmentTypeID                                 TypeID;                                                   // 0x01DC(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
    bool                                               bAlwaysTrigger;                                           // 0x01DD(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
    bool                                               TreatAsInherrent;                                         // 0x01DE(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
    unsigned char                                      UnknownData01[0x1];                                       // 0x01DF(0x0001) MISSED OFFSET
    unsigned char                                      UnknownData02[0x10];
    //struct FScriptMulticastDelegate                  OnCurrentCounterValueChanged;                             // 0x01E0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
    
    UFUNCTION(BlueprintCallable)
    static int GetUpgradeCostForEnchantmentTypeLevel(UPARAM() EEnchantmentTypeID Type, UPARAM() int Level) {
        return 0;
    }

    UFUNCTION(BlueprintCallable)
        static FText GetNameForEnchantmentType(UPARAM() EEnchantmentTypeID Type) {
        return FText();
    }

    UFUNCTION(BlueprintCallable)
        static FText GetLevelEffectDescriptionForEnchantmentType(UPARAM() EEnchantmentTypeID Type, UPARAM() int Level, UPARAM() float ItemPower) {
        return FText();
    }

    UFUNCTION(BlueprintCallable)
        static bool GetIsRarityForEnchantmentType(UPARAM() EEnchantmentTypeID Type, UPARAM() EEnchantmentRarity Rarity) {
        return true;
    }

    UFUNCTION(BlueprintCallable)
        static UTexture2D* GetIconTextureForEnchantmentType(UPARAM() class UObject* ref, UPARAM() EEnchantmentTypeID Type) {
        return NULL;
    }

    UFUNCTION(BlueprintCallable)
        static bool GetHasTagForEnchantmentType(UPARAM() EEnchantmentTypeID Type, UPARAM() EEnchantmentTag Tag) {
        return true;
    }

    UFUNCTION(BlueprintCallable)
        static EEnchantmentRarity GetEnchantmentTypeRarity(UPARAM() EEnchantmentTypeID Type) {
        return (EEnchantmentRarity)0;
    }

    UFUNCTION(BlueprintCallable)
        static EEnchantmentCategory GetEnchantmentTypeCategory(UPARAM() EEnchantmentTypeID Type) {
        return (EEnchantmentCategory)0;
    }

    //Blueprints do not accept: TArray<struct FItemBulletPoint>
    /*UFUNCTION(BlueprintCallable, BlueprintPure)
        static TArray<struct FItemBulletPoint> GetDisplayBulletPointsTextForEnchantmentType(UPARAM() EEnchantmentTypeID Type) {
        return TArray<struct FItemBulletPoint>();
    }*/

    UFUNCTION(BlueprintCallable)
        static FText GetDescriptionForEnchantmentType(UPARAM() EEnchantmentTypeID Type) {
        return FText();
    }

    UFUNCTION(BlueprintCallable)
        static bool GetCanBeUsedByMobsForEnchantmentType(UPARAM() EEnchantmentTypeID Type) {
        return true;
    }

    UFUNCTION(BlueprintCallable)
        static void BroadcastEnchantmentTriggeredEvent() {}
};


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
        return ESubPlatformType__E_SUBPLATFORM_BASE;
    }

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetPlatformMatch(UPARAM() int PlatformFlags)
    {
        return true;
    }

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EPlatformType GetPlatformEnum()
    {
        return EPlatformType__E_PLATFORM_PC;
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
        return EConfigurationType__E_CONFIG_SHIPPING;
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
