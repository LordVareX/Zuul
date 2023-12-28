-ignorewarnings
-keep class retrofit.** { *; }
-keep,includedescriptorclasses public class com.google.firebase.FirebaseApiNotAvailableException { *; }
-keep,includedescriptorclasses public class com.google.firebase.FirebaseException { *; }
-keep,includedescriptorclasses public class com.google.firebase.FirebaseNetworkException { *; }
-keep,includedescriptorclasses public class com.google.firebase.FirebaseTooManyRequestsException { *; }
-keep,includedescriptorclasses public class com.google.firebase.app.internal.cpp.Log { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.AdditionalUserInfo { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.AuthCredential { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.AuthResult { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.EmailAuthProvider { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FacebookAuthProvider { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FirebaseAuth { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FirebaseAuth$AuthStateListener { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FirebaseAuth$IdTokenListener { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FirebaseAuthActionCodeException { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FirebaseAuthEmailException { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FirebaseAuthException { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FirebaseAuthInvalidCredentialsException { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FirebaseAuthInvalidUserException { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FirebaseAuthRecentLoginRequiredException { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FirebaseAuthUserCollisionException { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FirebaseAuthWeakPasswordException { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FirebaseAuthWebException { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FirebaseUser { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.FirebaseUserMetadata { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.GetTokenResult { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.GithubAuthProvider { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.GoogleAuthProvider { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.OAuthProvider { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.OAuthProvider$Builder { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.OAuthProvider$CredentialBuilder { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.PhoneAuthCredential { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.PhoneAuthProvider { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.PhoneAuthProvider$ForceResendingToken { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.PhoneAuthProvider$OnVerificationStateChangedCallbacks { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.PlayGamesAuthProvider { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.SignInMethodQueryResult { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.TwitterAuthProvider { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.UserInfo { *; }
-keep,includedescriptorclasses public class com.google.firebase.auth.UserProfileChangeRequest$Builder { *; }
-keep,includedescriptorclasses public class com.google.firebase.example.LoggingUtils { * ; }
-keep,includedescriptorclasses public class java.util.concurrent.TimeUnit { *; }
-keepattributes *Annotation*
-keepattributes Signature
-keepclasseswithmembers class * { @retrofit.http.* <methods>; }